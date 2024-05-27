#include "main.h"

#define PD1  61        //  122/2 分成左右两半屏(122x32)

/**中文显示子程序
Page_: 页地址 0x00 - 0x03
Column_: 列地址 0x00 - 0x80
Code_ : 汉字字模数据 index
*/ 
void write_code_16x16(uchar page,uchar col,uchar* str_code) {
  unsigned char i,j,k;
  i = 0;
  j = 0;
  while(j<2) {
    Command = ((page + j) & 0x03) | 0xb8;   // 设置页地址
    WriteCommandE1();
    WriteCommandE2();
    k = col;                   // 列地址值
    while(k < col + 16){
      if (k < PD1) {              // 为左半屏显示区域(E1)
        Command = k;
        WriteCommandE1();         // 设置列地址值
        LCDData = str_code[i]; // 取汉字字模数据
        WriteDataE1();            // 写字模数据
      } else{                     // 为右半屏显示区域(E2)
        Command = k-PD1;
        WriteCommandE2();         // 设置列地址值
        LCDData = str_code[i]; // 取汉字字模数据
        WriteDataE2();            // 写字模数据
      };

      i++;
      if( ++k >= PD1 * 2) break;  // 列地址是否超出显示范围
    } ;
    j++;
  };
}

//英文显示子程序
void write_code_8x8(uchar page,uchar col,uchar* str_code){
	  unsigned char i,j,k;

		i = 0;
		j = 0;
	
		Command = ((page + j) & 0x03) | 0xb8;   // 设置页地址
    WriteCommandE1();
    WriteCommandE2();
    k = col;                   // 列地址值

      if (k < PD1) {              // 为左半屏显示区域(E1)
        Command = k;
        WriteCommandE1();         // 设置列地址值
        LCDData = str_code[i]; // 取汉字字模数据
        WriteDataE1();            // 写字模数据
      } else{                     // 为右半屏显示区域(E2)
        Command = k-PD1;
        WriteCommandE2();         // 设置列地址值
        LCDData = str_code[i]; // 取汉字字模数据
        WriteDataE2();            // 写字模数据
      };
      i++;
}