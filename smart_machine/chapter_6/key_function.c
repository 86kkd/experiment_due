#include"main.h"

uchar singal_type;

void direct_keyfn(unsigned char key)
{

	int display_bit;
	unsigned long int tem_freq=freq;
	int i;
	switch(key) {
	//display mode 0
	case 15:{
		Clear();
		// display number
		for (i=7;i>0;i--){
			display_bit = tem_freq%10;
			write_code_16x16(0x03,(0x01+i-2)<<4,&number[display_bit]);
			tem_freq/=10;
			if(tem_freq==0)break;
		}	
	}break;

	//diaplay mode 1
	case 'R':{
		display_name();
	}break;

	default:break;//其余情况不更新显示
	}
}