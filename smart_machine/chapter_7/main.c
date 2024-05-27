#include "main.h"

unsigned long int freq=0;
unsigned long int clock_period=1000;// բ��ʱ��
unsigned long int signal_period;
unsigned int time_over_counter=0;

void display_name (void) {
	unsigned char student_number[] ={1,4} ;
	uint index;
	
	Clear();

	for(index = 0; index < 3; index++)
	{
		write_code_16x16(0x02,(0x01+index+1)<<4,&chinese[index]);
	}
	
	//display name
	for(index = 0; index < 2; index++)
	{
		write_code_16x16(0x00,(0x01+index+2)<<4,&user_name[index]);
	}
	Delay500ms();
}

unsigned char read_key(void)
{
	unsigned char scan_data = 0x20;//��ɨ����IO�������
	unsigned char row = 0, col = 0;
	unsigned char key_pos = 0xff;
	//����Ƿ��а�������
	XBYTE[ADDR_KEY_WRITE] = 0x00;
	if((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f)//�а�������
	{
		//��������
		Delay5ms();
		
		//�����м��
		XBYTE[ADDR_KEY_WRITE] = scan_data;
		while((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f)//��⵽0x0fʱ���ҵ�����
		{
			col ++;
			scan_data  = scan_data >> 1;
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
	TMOD |= 0x01 | 0x00;      //ʹ��ģʽ1����ʱ�� C/T=0Ϊ��ʱģʽ��C/T=1Ϊ����ģʽ
	TH0=(15536-clock_period)>>8;          	//������ֵ
	TL0=(15536-clock_period);         
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

void reload_time0(){
	TH0=(15536-clock_period)>>8;          	
	TL0=(15536-clock_period); 
}
void reload_signal_time0(){
	TH0=(15536-signal_period)>>8;          	
	TL0=(15536-signal_period); 	
}

void reload_time1(){
	TH1=0;
	TL1=0;
}

void calculate_frequency(){
	freq = ((time_over_counter<<16)|(TH1<<8)|TL1)/clock_period;
	// reload time
	time_over_counter = 0;
	reload_time1();
}

void time0_interrupt() interrupt 1 {
	gengerage_singal();	
	reload_signal_time0();
}

void time1_interrrupt() interrupt 3{
	time_over_counter +=1;
}


void main(void) {

	
	uchar key_pos = 0xff;
	uchar tmp_key = 0xff;
	
	//LCD��ʼ��
	Init_LCD();
	// Init_Timer0();
	// Init_Timer1();
	
	display_name();
	
	while(1){
		key_pos = read_key();
		if(key_pos != 0xff){	
			//precess_keyfn(KEY_NUMBER[key_pos]);
			direct_keyfn(KEY_NUMBER[key_pos]);
			tmp_key = key_pos;
		}else {
			key_pos = tmp_key;
			//precess_keyfn(KEY_NUMBER[key_pos]);
			direct_keyfn(KEY_NUMBER[key_pos]);
		}
	}
}