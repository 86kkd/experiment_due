#include <reg51.h>
#include <absacc.h>
#include "font_library.h"

typedef unsigned char uchar;
typedef unsigned int uint;

uchar code KEY_NUMBER[]={

7,	8,	9,	10,	'T',	'R',

4,	5,	6,	11,	'S',	'M',

1,	2,	3,	12,	'H',	'L',

0,	15,	14,	13,	'X',	'N'
};//按键键名

//显示按键键名
#define MODE_0	(uchar)0
#define MODE_1	(uchar)1
#define MODE_2	(uchar)2
#define MODE_3	(uchar)3



#define ADDR_KEY_READ	0x9001
#define ADDR_KEY_WRITE	0x9002

xdata uchar CWADD1 _at_ 0x8000;   // 写指令代码地址(E1)
xdata uchar DWADD1 _at_ 0x8001;   // 写显示数据地址(E1)
xdata uchar CRADD1 _at_ 0x8002;   // 读状态字地址(E1)
xdata uchar DRADD1 _at_ 0x8003;   // 读显示数据地址(E1)

xdata uchar CWADD2 _at_ 0x8004;   // 写指令代码地址(E2)
xdata uchar DWADD2 _at_ 0x8005;   // 写显示数进地址(E2)
xdata uchar CRADD2 _at_ 0x8006;   // 读状态字地址(E2)
xdata uchar DRADD2 _at_ 0x8007;   // 读显示数据地址(E2)


uchar Column;
uchar Page_ ;  // 页地址寄存器 D1,DO:页地址
uchar Code_ ;  // 字符代码寄存器

uchar Command; // 指令寄存器
uchar LCDData; // 数据寄存器



uchar read_key(void);										//按键扫描
void Delay5ms();					// 延时程序											//软件延时
void precess_keyfn(uchar key_num);	//LCD显示模式切换
				 

void WriteCommandE1();		// 1.写指令代码子程序(E1)		 
void WriteDataE1();				// 2.写显示数据子程序(E1)		 
void ReadDataE1();				// 3.读显示数据子程序(E1)			 
void WriteCommandE2();		// 4.写指令代码子程序(E2)			 
void WriteDataE2();				// 5.写显示数据子程序(E2)			 
void ReadDataE2();				// 6.读显示数据子程序(E2)	 
void Init();							// 初始化程序	
void Clear();							// 清屏
void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_); // 中文显示子程序
void WriteEN8x8(void);		//英文显示子程序