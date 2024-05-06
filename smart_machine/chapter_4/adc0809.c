#include <reg51.h>

typedef unsigned char uchar;
typedef unsigned int uint;

void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_); // 中文显示子程序	


uchar ADC_CONVERT(sbit START_ALE,sbit EOC,sbit OE)		  //ADC转换开始函数
{
	uchar ADC_Date=0;
	START_ALE=1;				  //一个正脉冲
	START_ALE=0;
	while(!EOC);
	OE=1;
    ADC_Date=P0;
    return ADC_Date;
}

void display_ADC_Date(uchar ADC_Date)
{
	uint i=0;
	uchar display_bit ;

	for(i=0;i<3;i++){
		display_bit=ADC_Date%10;
		WriteCHN16x16(Page_=0x03,Column=(0x01+i)<<4,Code_=display_bit);				  //显示ADC转换值
		ADC_Date=ADC_Date*10;				  //清除显示
	}
}
