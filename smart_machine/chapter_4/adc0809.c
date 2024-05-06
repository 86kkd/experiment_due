#include <reg51.h>

typedef unsigned char uchar;
typedef unsigned int uint;

void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_); // ������ʾ�ӳ���	


uchar ADC_CONVERT(sbit START_ALE,sbit EOC,sbit OE)		  //ADCת����ʼ����
{
	uchar ADC_Date=0;
	START_ALE=1;				  //һ��������
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
		WriteCHN16x16(Page_=0x03,Column=(0x01+i)<<4,Code_=display_bit);				  //��ʾADCת��ֵ
		ADC_Date=ADC_Date*10;				  //�����ʾ
	}
}
