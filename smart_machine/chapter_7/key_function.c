#include"main.h"

uchar *output_signal;

code uchar period_tab[]={1,100,200,300,400};
code uchar clock_period_tab[]={100,200,300,400};
uchar period_index = 0;

uchar index = 0;
uint signal_quantity=255;

uchar start_gengrate=0;

void display_number(unsigned long int input){
	int display_bit;
	unsigned long int tmp=input;
	int i;Clear();
		// display number
	for (i=7;i>0;i--){
		display_bit = tmp%10;
		write_code_16x16(0x03,(0x01+i-2)<<4,&number[display_bit]);
		tmp/=10;
		if(tmp==0)break;
	}
}


void gengerage_signal(){

	DAC0832 = output_signal[index];
	index = (index+1)%signal_quantity;
}

void direct_keyfn(unsigned char key)
{
	switch(key) {
	//display mode 0
	case 9:{
		output_signal = square_table;
		display_number(period);
		Delay500ms();
	}break;
	
	case 6:{
		output_signal = sin_table;
		display_number(period);	
		Delay500ms();
	}break;
	
	case 3:{
		output_signal = triangle_table;
		display_number(period);
		Delay500ms();
	}break;
	
	case 14:{
		output_signal = up_sawtooth_table;
		display_number(period);
		Delay500ms();
	}break;
	
	case 11:{
		// signal_period = period_tab[(period_index+1)%5];
		// display_number(signal_period);

		clock_period = clock_period_tab[(period_index+1)%5];
		display_number(clock_period);

		Delay500ms();
	}break;
	//diaplay mode 1
	case 10:{
		display_name();
		if (start_gengrate==0){
			signal_period=period_tab[0];
			Init_Timer0();
			Init_Timer1();
			start_gengrate=1;
		}
		else{
			ET0=0;           //定时器中断
			TR0=0;	         //定时器开关
			ET1=0;           
			TR1=0;           
			start_gengrate=0;
		}
	}break;

	default:break;//其余情况不更新显示
	}
}