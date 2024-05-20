#include"main.h"

uchar singal_type;
code uchar period_tab[]={500,1000,2000,4000,5000};
uchar period_index = 0;

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


void gengerage_singal(){
	switch (singal_type)
	{
	case 0:{
		generateSquareWave();
	} break;

	case 1:{
		generateUpSawtoothWave();
	}break;

	case 2:{
		generateDownSawtoothWave();
	}break;

	case 3:{
		generateTriangleWave();
	}break;
	case 4:{
		generateSineWave();
	}	
	default:
		break;
	}
}

void direct_keyfn(unsigned char key)
{
	switch(key) {
	//display mode 0
	case 15:{
		// display_number(freq);		
		singal_type = (singal_type+1)%5;
		display_number(period);
	}break;
	case 15:{
		// display_number(freq);		
		period = period_tab[(period_index+1)%5];
		display_number(period);
	}break;
	//diaplay mode 1
	case 'R':{
		display_name();
	}break;

	default:break;//其余情况不更新显示
	}
}