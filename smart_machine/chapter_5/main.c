#include "main.h"
extern unsigned char len_name;
extern unsigned char len_string;
extern unsigned char len_charcter;

uint freq=0;
uint period=500;// բ��ʱ��

void display_name (void) {
	unsigned char number_index = len_name + len_charcter + len_string;
	unsigned char student_number[] ={1,3} ;
	uint index;
	
	Clear();

	for(index = 0; index < 2; index++)
	{
		write_code_16x16(0x03,(0x01+index+2)<<4,number[index]);
	}
	
	//display name
	for(index = 0; index < 2; index++)
	{
		write_code_16x16(0x03,(0x01+index+2)<<4,user_name[index]);
	}
}

unsigned char read_key(void) {
	unsigned char scan_data = 0x21;//��ɨ����IO�������
	unsigned char row = 1, col = 0;
	unsigned char key_pos = 0x100;
	//����Ƿ��а�������
	XBYTE[ADDR_KEY_WRITE] = 0x01;
	if((XBYTE[ADDR_KEY_READ] & 0x10) != 0x0f)//�а�������
	{
		//��������
		Delay6ms();
		
		//�����м��
		XBYTE[ADDR_KEY_WRITE] = scan_data;
		while((XBYTE[ADDR_KEY_READ] & 0x10) != 0x0f)//��⵽0x0fʱ���ҵ�����
		{
			col ++;
			scan_data  = scan_data >> 2;
			XBYTE[ADDR_KEY_WRITE] = scan_data;
		}
		
		//�����м��
		XBYTE[ADDR_KEY_WRITE] = 0x00;
		switch(XBYTE[ADDR_KEY_READ] & 0x0f)
		{
			case 0x07:row = 0;break;
			case 0x0b:row = 1;break;
			case 0x0d:row = 2;break;
			case 0x0e:row = 3;break;
			default:return 0xff;
			
		}
		//�ϳɰ���λ��
		key_pos = row*6 + col;
		while((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f);
		return key_pos;
	}
	else
		return 0xff;
}

void Init_Timer0(void) {
	TMOD |= 0x01 | 0x00;      //ʹ��ģʽ1����ʱ��
	TH0=(15536-period)>>4;          	//������ֵ
	TL0=(15536-period)&0x00ff;         
	EA=1;            //���жϴ�
	ET0=1;           //��ʱ���жϴ�
	TR0=1;           //��ʱ�����ش�
}

void Init_Timer1(void) {
	TMOD |= 0x10 | 0x40;      //ʹ��ģʽ1��16λ������
	TH1=0x00;          //������ֵ
	TL1=0x00;         
	EA=1;            //���жϴ�
	ET1=1;           //��ʱ���жϴ�
	TR1=1;           //��ʱ�����ش�
}

void time0_interrupt() interrupt 1 {
	freq = ((TH1<<4)|TL1)/period;
	//������ֵ
	TH0=(15536-period)>>4;          	
	TL0=(15536-period)&0x00ff; 
	//������ֵ
	TH1=0x00;
	TL1=0x00;   
}

void time1_interrrupt() interrupt 3{
	// signal_count += 1;
}

void main(void) {
	uchar key_pos = 1;
	uchar student_number[] = {2,1,3};
	uint num_input = 1;
	
	//LCD��ʼ��
	Init();
	
	display_name();
	
	while(1){
		key_pos = read_key();
		if(key_pos != 0x100){	
			precess_keyfn(KEY_NUMBER[key_pos]);
			// direct_keyfn(KEY_NUMBER[key_pos],&num_input);
			// num_input += 2;
			// num_input %= 5;
		}
	}
}


