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
};//按键键名

//显示按键键名
#define MODE_0	(unsigned char)0
#define MODE_1	(unsigned char)1
#define MODE_2	(unsigned char)2
#define MODE_3	(unsigned char)3

#define PD1  61        //  122/2 分成左右两半屏(122x32)

unsigned char Column;
unsigned char Page_ ;  // 页地址寄存器 D1,DO:页地址
unsigned char Code_ ;  // 字符代码寄存器

unsigned char Command; // 指令寄存器
unsigned char LCDData; // 数据寄存器

xdata unsigned char CWADD1 _at_ 0x8000;   // 写指令代码地址(E1)
xdata unsigned char DWADD1 _at_ 0x8001;   // 写显示数据地址(E1)
xdata unsigned char CRADD1 _at_ 0x8002;   // 读状态字地址(E1)
xdata unsigned char DRADD1 _at_ 0x8003;   // 读显示数据地址(E1)

xdata unsigned char CWADD2 _at_ 0x8004;   // 写指令代码地址(E2)
xdata unsigned char DWADD2 _at_ 0x8005;   // 写显示数进地址(E2)
xdata unsigned char CRADD2 _at_ 0x8006;   // 读状态字地址(E2)
xdata unsigned char DRADD2 _at_ 0x8007;   // 读显示数据地址(E2)

////英文字模库    8x8 点阵
//code unsigned char EETAB[][8]={
//        {0x38,0x44,0x44,0x44,0x44,0x44,0x38,0x00},  // 0
//        {0x10,0x30,0x50,0x10,0x10,0x10,0x7c,0x00},  // 1
//        {0x38,0x44,0x04,0x08,0x10,0x20,0x7c,0x00},  // 2
//        {0x78,0x84,0x04,0x38,0x04,0x84,0x78,0x00}}; // 3

// 中文字模库   16x16点阵
code unsigned char CCTAB[][32] ={
        {0x08,0x28,0x49,0x8a,0x0e,0x88,0x78,0x0c,0x08,0x00,0xfc,0x00,0x00,0xff,0x00,0x00,
0x40,0x20,0x10,0x09,0x06,0x09,0x30,0x60,0x00,0x00,0x0f,0x40,0x80,0x7f,0x00,0x00,},//刘

        {0x80,0x44,0x24,0x9f,0x84,0xa4,0xc4,0xbc,0x80,0xbc,0xa4,0xe4,0xa4,0x3e,0x04,0x00,
0x00,0x00,0x80,0x9f,0x40,0x40,0x20,0x1e,0x20,0x20,0x40,0x5f,0x80,0x00,0x00,0x00},//贺

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

unsigned char key_scan(void);										//按键扫描
void Delay5ms();																//软件延时
void DisplayMode_switch(unsigned char key_num);	//LCD显示模式切换
				 

void WriteCommandE1();		// 1.写指令代码子程序(E1)		 
void WriteDataE1();				// 2.写显示数据子程序(E1)		 
void ReadDataE1();				// 3.读显示数据子程序(E1)			 
void WriteCommandE2();		// 4.写指令代码子程序(E2)			 
void WriteDataE2();				// 5.写显示数据子程序(E2)			 
void ReadDataE2();				// 6.读显示数据子程序(E2)	 
void Init();							// 初始化程序	
void Clear();							// 清屏
void Delay();							// 延时程序
void WriteCHN16x16();			// 中文显示子程序
void WriteEN8x8(void);		//英文显示子程序


void main(void)
{
	unsigned char key_pos = 0;
		
	//display_key(0xff,0x9004,0x9002,0x00);
	Delay5ms();	
	//LCD初始化
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
	unsigned char scan_data = 0x20;//列扫描用IO输出数据
	unsigned char row = 0, col = 0;
	unsigned char key_pos = 0xff;
	//检测是否有按键按下
	XBYTE[ADDR_KEY_WRITE] = 0x00;
	if((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f)//有按键按下
	{
		//按键消抖
		Delay5ms();
			
		
		//进行列检测
		XBYTE[0x9004] = 0x00;
		XBYTE[ADDR_KEY_WRITE] = scan_data;
		while((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f)//检测到0x0f时即找到该列
		{
			col ++;
			scan_data  = scan_data >> 1;
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
	else if((XBYTE[ADDR_KEY_READ] & 0x0f) == 0x0f)//没有按键按下
	{
		
		return 0xff;//返回特殊值
		
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


// 中文显示子程序
void WriteCHN16x16()
{
  unsigned char i,j,k;

  i = 0;
  j = 0;
  while(j<2) {
    Command = ((Page_ + j) & 0x03) | 0xb8;   // 设置页地址
    WriteCommandE1();
    WriteCommandE2();
    k = Column;                   // 列地址值
    while(k < Column + 16){
      if (k < PD1) {              // 为左半屏显示区域(E1)
        Command = k;
        WriteCommandE1();         // 设置列地址值
        LCDData = CCTAB[Code_][i]; // 取汉字字模数据
        WriteDataE1();            // 写字模数据
      } else{                     // 为右半屏显示区域(E2)
        Command = k-PD1;
        WriteCommandE2();         // 设置列地址值
        LCDData = CCTAB[Code_][i]; // 取汉字字模数据
        WriteDataE2();            // 写字模数据
      };

      i++;
      if( ++k >= PD1 * 2) break;  // 列地址是否超出显示范围
    } ;
    j++;
  };
}

//英文显示子程序
void WriteEN8x8(void)
{
	  unsigned char i,j,k;

		i = 0;
		j = 0;
	
		Command = ((Page_ + j) & 0x03) | 0xb8;   // 设置页地址
    WriteCommandE1();
    WriteCommandE2();
    k = Column;                   // 列地址值

      if (k < PD1) {              // 为左半屏显示区域(E1)
        Command = k;
        WriteCommandE1();         // 设置列地址值
        LCDData = CCTAB[Code_][i]; // 取汉字字模数据
        WriteDataE1();            // 写字模数据
      } else{                     // 为右半屏显示区域(E2)
        Command = k-PD1;
        WriteCommandE2();         // 设置列地址值
        LCDData = CCTAB[Code_][i]; // 取汉字字模数据
        WriteDataE2();            // 写字模数据
      };

      i++;
}

