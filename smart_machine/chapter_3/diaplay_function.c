typedef unsigned char uchar;
typedef unsigned int uint;

extern xdata unsigned char CWADD1 ;   // 写指令代码地址(E1)
extern xdata unsigned char DWADD1 ;   // 写显示数据地址(E1)
extern xdata unsigned char CRADD1 ;   // 读状态字地址(E1)
extern xdata unsigned char DRADD1 ;   // 读显示数据地址(E1)

extern xdata unsigned char CWADD2 ;   // 写指令代码地址(E2)
extern xdata unsigned char DWADD2 ;   // 写显示数进地址(E2)
extern xdata unsigned char CRADD2 ;   // 读状态字地址(E2)
extern xdata unsigned char DRADD2 ;   // 读显示数据地址(E2)


extern unsigned char Column;
extern unsigned char Page_ ;  // 页地址寄存器 D1,DO:页地址
extern unsigned char Code_ ;  // 字符代码寄存器

extern unsigned char Command; // 指令寄存器
extern unsigned char LCDData; // 数据寄存器

extern code unsigned char CCTAB[][32];

void WriteCommandE1();
void WriteCommandE2();
void WriteDataE1();
void WriteDataE2();

#define PD1  61        //  122/2 分成左右两半屏(122x32)

// 中文显示子程序
void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_)
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