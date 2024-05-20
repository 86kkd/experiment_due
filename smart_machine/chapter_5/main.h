#include <reg51.h>
#include <absacc.h>
typedef unsigned char uchar;
typedef unsigned int uint;

#define ADDR_KEY_READ	0x9001
#define ADDR_KEY_WRITE	0x9002

// 液晶代码显示
extern xdata uchar CWADD1 ;   // 写指令代码地址(E1)
extern xdata uchar DWADD1 ;   // 写显示数据地址(E1)
extern xdata uchar CRADD1 ;   // 读状态字地址(E1)
extern xdata uchar DRADD1 ;   // 读显示数据地址(E1)

extern xdata uchar CWADD2 ;   // 写指令代码地址(E2)
extern xdata uchar DWADD2 ;   // 写显示数进地址(E2)
extern xdata uchar CRADD2 ;   // 读状态字地址(E2)
extern xdata uchar DRADD2 ;   // 读显示数据地址(E2)


extern code uchar KEY_NUMBER[];
extern code uchar user_name[][32];
extern code uchar number[][32];
extern code uchar chinese[][32];
extern code uchar math_char[][32];

extern unsigned char Command; // 指令寄存器
extern unsigned char LCDData; // 数据寄存器

uchar read_key(void);										//按键扫描

void Delay5ms();					// 延时程序											//软件延时
void Delay500ms();

void precess_keyfn(uchar key_num);	//LCD显示模式切换
void direct_keyfn(unsigned char key);

void WriteCommandE1();		// 1.写指令代码子程序(E1)		 
void WriteDataE1();				// 2.写显示数据子程序(E1)		 
void ReadDataE1();				// 3.读显示数据子程序(E1)			 
void WriteCommandE2();		// 4.写指令代码子程序(E2)			 
void WriteDataE2();				// 5.写显示数据子程序(E2)			 
void ReadDataE2();				// 6.读显示数据子程序(E2)	 

void Init();							// 初始化程序	
void Clear();							// 清屏
void write_code_8x8(uchar Page_,uchar Column,uchar Code_);		//英文显示子程序
void write_code_16x16(uchar page,uchar col,uchar* str_code);// 中文显示子程序