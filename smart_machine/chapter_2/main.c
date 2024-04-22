#include <reg51.h>
#include <absacc.h>
#define ADDR_KEY_READ			0x9001
#define ADDR_KEY_WRITE		0x9002
typedef unsigned char uchar;
typedef unsigned int uint;

unsigned char code KEY_NUMBER[]={

7,	8,	9,	10,	'T',	'R',

4,	5,	6,	11,	'S',	'M',

1,	2,	3,	12,	'H',	'L',

0,	15,	14,	13,	'X',	'N'
};//��������

//��ʾ��������
#define MODE_0	(unsigned char)0
#define MODE_1	(unsigned char)1
#define MODE_2	(unsigned char)2
#define MODE_3	(unsigned char)3

#define PD1  61        //  122/2 �ֳ�����������(122x32)

unsigned char Column;
unsigned char Page_ ;  // ҳ��ַ�Ĵ��� D1,DO:ҳ��ַ
unsigned char Code_ ;  // �ַ�����Ĵ���

unsigned char Command; // ָ��Ĵ���
unsigned char LCDData; // ���ݼĴ���

xdata unsigned char CWADD1 _at_ 0x8000;   // дָ������ַ(E1)
xdata unsigned char DWADD1 _at_ 0x8001;   // д��ʾ���ݵ�ַ(E1)
xdata unsigned char CRADD1 _at_ 0x8002;   // ��״̬�ֵ�ַ(E1)
xdata unsigned char DRADD1 _at_ 0x8003;   // ����ʾ���ݵ�ַ(E1)

xdata unsigned char CWADD2 _at_ 0x8004;   // дָ������ַ(E2)
xdata unsigned char DWADD2 _at_ 0x8005;   // д��ʾ������ַ(E2)
xdata unsigned char CRADD2 _at_ 0x8006;   // ��״̬�ֵ�ַ(E2)
xdata unsigned char DRADD2 _at_ 0x8007;   // ����ʾ���ݵ�ַ(E2)

////Ӣ����ģ��    8x8 ����
//code unsigned char EETAB[][8]={
//        {0x38,0x44,0x44,0x44,0x44,0x44,0x38,0x00},  // 0
//        {0x10,0x30,0x50,0x10,0x10,0x10,0x7c,0x00},  // 1
//        {0x38,0x44,0x04,0x08,0x10,0x20,0x7c,0x00},  // 2
//        {0x78,0x84,0x04,0x38,0x04,0x84,0x78,0x00}}; // 3

// ������ģ��   16x16����
code unsigned char CCTAB[][32] ={
        {0x08,0x28,0x49,0x8a,0x0e,0x88,0x78,0x0c,0x08,0x00,0xfc,0x00,0x00,0xff,0x00,0x00,
0x40,0x20,0x10,0x09,0x06,0x09,0x30,0x60,0x00,0x00,0x0f,0x40,0x80,0x7f,0x00,0x00,},//��

        {0x80,0x44,0x24,0x9f,0x84,0xa4,0xc4,0xbc,0x80,0xbc,0xa4,0xe4,0xa4,0x3e,0x04,0x00,
0x00,0x00,0x80,0x9f,0x40,0x40,0x20,0x1e,0x20,0x20,0x40,0x5f,0x80,0x00,0x00,0x00},//��

};

void display_key(uchar key_char, uint display_bus, uint display_bit_bus, uchar bit_)
{
    // display key on display display_key(0xff,0x9004,0x9002,0x00);
    uchar xdata *display_bus_pointer;
    display_bus_pointer = 0x9004;
    *display_bus_pointer = 0xff;
    // set display bit
    display_bus_pointer = 0x9002;
    *display_bus_pointer = 0x00;
    delay_10ms();
}

unsigned char key_scan(void);										//����ɨ��
void Delay5ms();																//�����ʱ
void DisplayMode_switch(unsigned char key_num);	//LCD��ʾģʽ�л�
				 

void WriteCommandE1();		// 1.дָ������ӳ���(E1)		 
void WriteDataE1();				// 2.д��ʾ�����ӳ���(E1)		 
void ReadDataE1();				// 3.����ʾ�����ӳ���(E1)			 
void WriteCommandE2();		// 4.дָ������ӳ���(E2)			 
void WriteDataE2();				// 5.д��ʾ�����ӳ���(E2)			 
void ReadDataE2();				// 6.����ʾ�����ӳ���(E2)	 
void Init();							// ��ʼ������	
void Clear();							// ����
void Delay();							// ��ʱ����
void WriteCHN16x16();			// ������ʾ�ӳ���
void WriteEN8x8(void);		//Ӣ����ʾ�ӳ���


void main(void)
{
	unsigned char key_pos = 0;
		
	//display_key(0xff,0x9004,0x9002,0x00);
	Delay5ms();	
	//LCD��ʼ��
	Init();
  Clear();

			Page_ = 0x03;
			Column = 0x00+5;
			Code_ = 0x1C;
			WriteCHN16x16();
	
			Page_ = 0x03;
			Column = 0x10+5;
			Code_ = 0x1D;
			WriteCHN16x16();
	
			Page_ = 0x03;
			Column = 0x20+5;
			Code_ = 0x1E;
			WriteCHN16x16();
	
	
	
			Page_ = 0x03;
			Column = 0x30+5;
			Code_ = 0x00;
			WriteCHN16x16();
	
			Page_ = 0x03;
			Column = 0x40+5;
			Code_ = 0x01;
			WriteCHN16x16();
	
			Page_ = 0x03;
			Column = 0x50+5;
			Code_ = 0x02;
			WriteCHN16x16();
			
			Page_ = 0x03;
			Column = 0x60+5;
			Code_ = 0x03;
			WriteCHN16x16();
			
			while(key_scan() == 0xff);
			Clear();
			display_key(0xff,0x9004,0x9002,0x00);
	
	while(1)
	{
		key_pos = key_scan();
		if(key_pos != 0xff)
			DisplayMode_switch(KEY_NUMBER[key_pos]);
		
	}
	
	
}


unsigned char key_scan(void)
{
	unsigned char scan_data = 0x20;//��ɨ����IO�������
	unsigned char row = 0, col = 0;
	unsigned char key_pos = 0xff;
	//����Ƿ��а�������
	XBYTE[ADDR_KEY_WRITE] = 0x00;
	if((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f)//�а�������
	{
		//��������
		Delay5ms();
			
		
		//�����м��
		XBYTE[0x9004] = 0x00;
		XBYTE[ADDR_KEY_WRITE] = scan_data;
		while((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f)//��⵽0x0fʱ���ҵ�����
		{
			col ++;
			scan_data  = scan_data >> 1;
			XBYTE[ADDR_KEY_WRITE] = scan_data;
			
		}
		
		//�����м��
		XBYTE[ADDR_KEY_WRITE] = 0x00;
		switch(XBYTE[ADDR_KEY_READ] & 0x0f)
		{
			case 0x07:row = 0;break;
			case 0x0b:row = 1;break;
			case 0x0d:row = 2;break;
			case 0x0e:row = 3;break;
			default:key_pos = 0xff;break;
			
		}
		
		//�ϳɰ���λ��
		key_pos = row*6 + col;
		
		while((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f);
		
		
		return key_pos;
		
	}
	else if((XBYTE[ADDR_KEY_READ] & 0x0f) == 0x0f)//û�а�������
	{
		
		return 0xff;//��������ֵ
		
	}
	
}




void Delay5ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 10;
	j = 183;
	do
	{
		while (--j);
	} while (--i);
}


// ������ʾ�ӳ���
void WriteCHN16x16()
{
  unsigned char i,j,k;

  i = 0;
  j = 0;
  while(j<2) {
    Command = ((Page_ + j) & 0x03) | 0xb8;   // ����ҳ��ַ
    WriteCommandE1();
    WriteCommandE2();
    k = Column;                   // �е�ֵַ
    while(k < Column + 16){
      if (k < PD1) {              // Ϊ�������ʾ����(E1)
        Command = k;
        WriteCommandE1();         // �����е�ֵַ
        LCDData = CCTAB[Code_][i]; // ȡ������ģ����
        WriteDataE1();            // д��ģ����
      } else{                     // Ϊ�Ұ�����ʾ����(E2)
        Command = k-PD1;
        WriteCommandE2();         // �����е�ֵַ
        LCDData = CCTAB[Code_][i]; // ȡ������ģ����
        WriteDataE2();            // д��ģ����
      };

      i++;
      if( ++k >= PD1 * 2) break;  // �е�ַ�Ƿ񳬳���ʾ��Χ
    } ;
    j++;
  };
}

//Ӣ����ʾ�ӳ���
void WriteEN8x8(void)
{
	  unsigned char i,j,k;

		i = 0;
		j = 0;
	
		Command = ((Page_ + j) & 0x03) | 0xb8;   // ����ҳ��ַ
    WriteCommandE1();
    WriteCommandE2();
    k = Column;                   // �е�ֵַ

      if (k < PD1) {              // Ϊ�������ʾ����(E1)
        Command = k;
        WriteCommandE1();         // �����е�ֵַ
        LCDData = CCTAB[Code_][i]; // ȡ������ģ����
        WriteDataE1();            // д��ģ����
      } else{                     // Ϊ�Ұ�����ʾ����(E2)
        Command = k-PD1;
        WriteCommandE2();         // �����е�ֵַ
        LCDData = CCTAB[Code_][i]; // ȡ������ģ����
        WriteDataE2();            // д��ģ����
      };

      i++;
}

