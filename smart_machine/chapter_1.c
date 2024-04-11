#include <8051.h>
// #include <reg51.h>
#ifdef REG8051_H
#define xdata __xdata
#endif

#define uchar unsigned char
#define uint unsigned int

// restore key to 40H
uchar key = 0x40;
// setting key/led cs
uint cs_key = 0x8000;
// setting bus to display
uchar bit_set = 0;
uint function_key = 0x3f;
//                0     1      2    3       4      5    6     7    8     9     a    b      c    d      e     f    dp
uchar key_tab[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x80};

// uchar key_tab[][] = {{},
//                     {},
//                     {},
//                     {}}

// delay 10ms
void delay_10ms(void)
{
    uint i, j;
    for (i = 0; i < 100; i++)
        for (j = 0; j < 120; j++)
            ;
}

// sacnning keys from 0xX000 to 0xX008
uchar read_key(uint read_bus, uint write_bus)
{
    uchar xdata *key_bus_pointer;
    uchar i;
    uint key;
    for (i = 0; i < 8; i++)
    {
        // set read bus address
        key_bus_pointer = write_bus | (i * 2);
        // wite 0 to output
        *key_bus_pointer = 0;
        // read form read_buf
        key_bus_pointer = read_bus;
        key = *key_bus_pointer;
        delay_10ms();
        if (key != 0xFF)
            break;
    }
    if (i >= 8)
    {
        // low 8 bit is col hight 8 bit is row
        key = ~key << 8 | i;
    }
    else //check if there is key
    {
        key = 0;
    }
    return key;
}
void display_key(uchar key_char, uint display_bus, uint display_bit_bus, uchar bit)
{
    // display key on display
    uchar xdata *display_bus_pointer;
    display_bus_pointer = display_bus;
    *display_bus_pointer = key_char;
    // set display bit
    display_bus_pointer = display_bit_bus;
    *display_bus_pointer = bit;
    delay_10ms();
}
void main()
{
    uint write_bus = cs_key | 0x02;
    uint read_bus = cs_key | 0x01;
    uint display_bus = cs_key | 0x04;
    uint display_bit_bus = cs_key | 0x02;
    while (1)
    {
        /* code */
        uchar key = read_key(read_bus, write_bus);
        if (key == 0) continue;// if no key continue

        uchar row = key & 0x0f;
        uchar col = key >> 4;
        if (key == function_key)
        {
            bit_set = (bit_set << 1);
        }
        uchar display_char = key_tab[row * 4 + col];
        display_key(display_char, display_bus, display_bit_bus, bit_set);
    }
}