// #include <8051.h>
#include <reg51.h>
#include <absacc.h>
#ifdef REG8051_H
#define xdata __xdata
#endif

#define uchar unsigned char
#define uint unsigned int

#define ADDR_KEY_READ	0x9001
#define ADDR_KEY_WRITE	0x9002
// restore key to 40H
uchar key = 0x40;
// setting key/led cs
uint cs_key = 0x9000;
// setting bus to display
uchar bit_set = 0;
uint function_key = 0x3f;
//                0     1      2    3       4      5    6     7    8     9     a    b      c    d      e     f    dp
uchar key_tab[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f,
                 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x80};

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
unsigned char read_key(void)
{
	unsigned char scan_data = 0x01;//列扫描用IO输出数据
	unsigned char row = 0, col = 0;
	unsigned char key_pos = 0xff;
	//检测是否有按键按下
	XBYTE[ADDR_KEY_WRITE] = 0x00;
	if((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f)//有按键按下
	{
		//按键消抖
		Delay5ms();
		
		//进行列检测
		XBYTE[ADDR_KEY_WRITE] = scan_data;
		while((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f)//检测到0x0f时即找到该列
		{
			col ++;
			scan_data  = scan_data << 1;
			XBYTE[ADDR_KEY_WRITE] = scan_data;
		}
		
		//进行行检测
		XBYTE[ADDR_KEY_WRITE] = 0x00;
		switch(XBYTE[ADDR_KEY_READ] & 0x0f)
		{
			case 0x07:row = 0;break;
			case 0x0b:row = 1;break;
			case 0x0d:row = 2;break;
			case 0x0e:row = 3;break;
			default:key_pos = 0xff;break;
			
		}
		
		//合成按键位置
		key_pos = row*6 + col;
		
		while((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f);

		
		
		return key_pos;
		
	}
	else
		return 0xff;
}

void display_key(uchar key_char, uint display_bus, uint display_bit_bus, uchar bit_)
{
    // display key on display
    uchar xdata *display_bus_pointer;
    display_bus_pointer = display_bus;
    *display_bus_pointer = key_char;
    // set display bit
    display_bus_pointer = display_bit_bus;
    *display_bus_pointer = bit_;
    delay_10ms();
}
void main()
{
    uint write_bus = cs_key | 0x02;
    uint read_bus = cs_key | 0x01;
    uint display_bus = cs_key | 0x04;
    uint display_bit_bus = cs_key | 0x02;
	  uchar row;
	  uchar col;
	  uchar display_char;
	
    while (1)
    {
        /* code */
        uchar key = read_key();
        if (key == 0) continue;// if no key continue

        row = key & 0x0f;
        col = key >> 4;
        if (key == function_key)
        {
            bit_set = (bit_set << 1);
        }
        display_char = key_tab[row * 4 + col];
        display_key(display_char, display_bus, display_bit_bus, bit_set);
    }
}