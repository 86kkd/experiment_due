#include <reg51.h>
#include <absacc.h>
#include "font_library.h"

typedef unsigned char uchar;
typedef unsigned int uint;

extern uchar code KEY_NUMBER[];

//��ʾ��������
#define MODE_0	(uchar)0
#define MODE_1	(uchar)1
#define MODE_2	(uchar)2
#define MODE_3	(uchar)3



#define ADDR_KEY_READ	0x9001
#define ADDR_KEY_WRITE	0x9002

xdata uchar CWADD1 _at_ 0x8000;   // дָ������ַ(E1)
xdata uchar DWADD1 _at_ 0x8001;   // д��ʾ���ݵ�ַ(E1)
xdata uchar CRADD1 _at_ 0x8002;   // ��״̬�ֵ�ַ(E1)
xdata uchar DRADD1 _at_ 0x8003;   // ����ʾ���ݵ�ַ(E1)

xdata uchar CWADD2 _at_ 0x8004;   // дָ������ַ(E2)
xdata uchar DWADD2 _at_ 0x8005;   // д��ʾ������ַ(E2)
xdata uchar CRADD2 _at_ 0x8006;   // ��״̬�ֵ�ַ(E2)
xdata uchar DRADD2 _at_ 0x8007;   // ����ʾ���ݵ�ַ(E2)


uchar Column;
uchar Page_ ;  // ҳ��ַ�Ĵ��� D1,DO:ҳ��ַ
uchar Code_ ;  // �ַ�����Ĵ���



uchar read_key(void);										//����ɨ��
void Delay5ms();					// ��ʱ����											//�����ʱ
void precess_keyfn(uchar key_num);	//LCD��ʾģʽ�л�
				 

void WriteCommandE1();		// 1.дָ������ӳ���(E1)		 
void WriteDataE1();				// 2.д��ʾ�����ӳ���(E1)		 
void ReadDataE1();				// 3.����ʾ�����ӳ���(E1)			 
void WriteCommandE2();		// 4.дָ������ӳ���(E2)			 
void WriteDataE2();				// 5.д��ʾ�����ӳ���(E2)			 
void ReadDataE2();				// 6.����ʾ�����ӳ���(E2)	 
void Init();							// ��ʼ������	
void Clear();							// ����
void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_); // ������ʾ�ӳ���
void WriteCHN8x8(uchar Page_,uchar Column,uchar Code_);		//Ӣ����ʾ�ӳ���
void ADC_CONVERT(sbit START_ALE,sbit EOC,sbit OE);		  //ADCת����ʼ����
void keyfn(unsigned char key, uchar ADC_Date)
void delay_ms(unsigned int time);