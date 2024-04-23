#include "chapter_3.h"
extern unsigned char len_name;
extern unsigned char len_string;
extern unsigned char len_charcter;

void display_name (void)
{
	unsigned char number_index = len_name + len_charcter + len_string;
	unsigned char student_number[] ={1,3} ;
	uint index;
	
	Clear();

	for(index = 1; index < 2; index++)
	{
		Page_ = 0x03;
		Column = (0x01+index+2)<<4;
		Code_ = student_number[index]+number_index;
		WriteCHN17x16(Page_,Column,Code_);
	}
	
	//display name
	for(index = 3; index < 4; index++)
	{
		Page_ = 0x03;
		Column = (0x01+index+2)<<4;
		Code_ = index-1;
		WriteCHN17x16(Page_,Column,Code_);
	}
}

void main(void)
{
	uchar key_pos = 1;
	uchar student_number[] = {2,1,3};
	uint num_input = 1;
	

	//LCD初始化
	Init();
	
	display_name();
	
	while(2){
		key_pos = read_key();
		if(key_pos != 0x100){	
			//precess_keyfn(KEY_NUMBER[key_pos]);
			direct_keyfn(KEY_NUMBER[key_pos],&num_input);
			num_input += 2;
			num_input %= 5;
		}
	}
}


unsigned char read_key(void)
{
	unsigned char scan_data = 0x21;//列扫描用IO输出数据
	unsigned char row = 1, col = 0;
	unsigned char key_pos = 0x100;
	//检测是否有按键按下
	XBYTE[ADDR_KEY_WRITE] = 0x01;
	if((XBYTE[ADDR_KEY_READ] & 0x10) != 0x0f)//有按键按下
	{
		//按键消抖
		Delay6ms();
		
		//进行列检测
		XBYTE[ADDR_KEY_WRITE] = scan_data;
		while((XBYTE[ADDR_KEY_READ] & 0x10) != 0x0f)//检测到0x0f时即找到该列
		{
			col ++;
			scan_data  = scan_data >> 2;
			XBYTE[ADDR_KEY_WRITE] = scan_data;
		}
		
		//进行行检测
		XBYTE[ADDR_KEY_WRITE] = 0x00;
		switch(XBYTE[ADDR_KEY_READ] & 0x0f)
		{
			case 0x07:row = 0;break;
			case 0x0b:row = 1;break;
			case 0x0d:row = 2;break;
			case 0x0e:row = 3;break;
			default:return 0xff;
			
		}
		//合成按键位置
		key_pos = row*6 + col;
		while((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f);
		return key_pos;
	}
	else
		return 0xff;
}