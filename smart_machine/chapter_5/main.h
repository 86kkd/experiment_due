#include <reg51.h>
#include <absacc.h>
#include "font_library.h"


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
void direct_keyfn(unsigned char key);

void WriteCommandE1();		// 1.дָ������ӳ���(E1)		 
void WriteDataE1();				// 2.д��ʾ�����ӳ���(E1)		 
void ReadDataE1();				// 3.����ʾ�����ӳ���(E1)			 
void WriteCommandE2();		// 4.дָ������ӳ���(E2)			 
void WriteDataE2();				// 5.д��ʾ�����ӳ���(E2)			 
void ReadDataE2();				// 6.����ʾ�����ӳ���(E2)	 
void Init();							// ��ʼ������	
void Clear();							// ����
void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_); // ������ʾ�ӳ���
void WriteEN8x8(uchar Page_,uchar Column,uchar Code_);		//Ӣ����ʾ�ӳ���
void write_code_16x16(uchar page,uchar col,uchar* str_code);