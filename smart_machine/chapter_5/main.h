#include <reg51.h>
#include <absacc.h>
typedef unsigned char uchar;
typedef unsigned int uint;

#define ADDR_KEY_READ	0x9001
#define ADDR_KEY_WRITE	0x9002

// Һ��������ʾ
extern xdata uchar CWADD1 ;   // дָ������ַ(E1)
extern xdata uchar DWADD1 ;   // д��ʾ���ݵ�ַ(E1)
extern xdata uchar CRADD1 ;   // ��״̬�ֵ�ַ(E1)
extern xdata uchar DRADD1 ;   // ����ʾ���ݵ�ַ(E1)

extern xdata uchar CWADD2 ;   // дָ������ַ(E2)
extern xdata uchar DWADD2 ;   // д��ʾ������ַ(E2)
extern xdata uchar CRADD2 ;   // ��״̬�ֵ�ַ(E2)
extern xdata uchar DRADD2 ;   // ����ʾ���ݵ�ַ(E2)


extern code uchar KEY_NUMBER[];
extern code uchar user_name[][32];
extern code uchar number[][32];
extern code uchar chinese[][32];
extern code uchar math_char[][32];

extern unsigned char Command; // ָ��Ĵ���
extern unsigned char LCDData; // ���ݼĴ���

uchar read_key(void);										//����ɨ��

void Delay5ms();					// ��ʱ����											//�����ʱ
void Delay500ms();

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
void write_code_8x8(uchar Page_,uchar Column,uchar Code_);		//Ӣ����ʾ�ӳ���
void write_code_16x16(uchar page,uchar col,uchar* str_code);// ������ʾ�ӳ���