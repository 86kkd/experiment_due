#include <reg51.h>
#include <absacc.h>
#include "font_library.h"

typedef unsigned char uchar;

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



#define ADDR_KEY_READ	0x9001
#define ADDR_KEY_WRITE	0x9002

xdata unsigned char CWADD1 _at_ 0x8000;   // дָ������ַ(E1)
xdata unsigned char DWADD1 _at_ 0x8001;   // д��ʾ���ݵ�ַ(E1)
xdata unsigned char CRADD1 _at_ 0x8002;   // ��״̬�ֵ�ַ(E1)
xdata unsigned char DRADD1 _at_ 0x8003;   // ����ʾ���ݵ�ַ(E1)

xdata unsigned char CWADD2 _at_ 0x8004;   // дָ������ַ(E2)
xdata unsigned char DWADD2 _at_ 0x8005;   // д��ʾ������ַ(E2)
xdata unsigned char CRADD2 _at_ 0x8006;   // ��״̬�ֵ�ַ(E2)
xdata unsigned char DRADD2 _at_ 0x8007;   // ����ʾ���ݵ�ַ(E2)


unsigned char Column;
unsigned char Page_ ;  // ҳ��ַ�Ĵ��� D1,DO:ҳ��ַ
unsigned char Code_ ;  // �ַ�����Ĵ���

unsigned char Command; // ָ��Ĵ���
unsigned char LCDData; // ���ݼĴ���



unsigned char read_key(void);										//����ɨ��
void Delay5ms();					// ��ʱ����											//�����ʱ
void precess_keyfn(unsigned char key_num);	//LCD��ʾģʽ�л�
				 

void WriteCommandE1();		// 1.дָ������ӳ���(E1)		 
void WriteDataE1();				// 2.д��ʾ�����ӳ���(E1)		 
void ReadDataE1();				// 3.����ʾ�����ӳ���(E1)			 
void WriteCommandE2();		// 4.дָ������ӳ���(E2)			 
void WriteDataE2();				// 5.д��ʾ�����ӳ���(E2)			 
void ReadDataE2();				// 6.����ʾ�����ӳ���(E2)	 
void Init();							// ��ʼ������	
void Clear();							// ����
void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_); // ������ʾ�ӳ���
void WriteEN8x8(void);		//Ӣ����ʾ�ӳ���