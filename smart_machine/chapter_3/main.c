#include "main.h"


void main(void)
{
	uchar key_pos = 0;
	uchar Code [] = {0x1c,0x1d,0x1e,0x00,0x01,0x02,0x03};
	uchar index;

	//LCD初始化
	Init();
	Clear();

	//display name
	for(index = 0; index < 2; index++)
	{
		Page_ = 0x03;
		Column = (0x00+index)<<4 + 5;
		Code_ = Code[index];
		WriteCHN16x16(Page_,Column,Code_);
	}
	while(read_key() == 0xff);
	Clear();
	
	while(1)
	{
		key_pos = read_key();
		if(key_pos != 0xff)
			precess_keyfn(KEY_NUMBER[key_pos]);
		
	}
	
}


unsigned char read_key(void)
{
	unsigned char scan_data = 0x20;//列扫描用IO输出数据
	unsigned char row = 0, col = 0;
	unsigned char key_pos = 0xff;
	//检测是否有按键按下
	XBYTE[ADDR_KEY_WRITE] = 0x00;
	if((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f)//有按键按下
	{
		//按键消抖
		Delay5ms();
		
		//进行列检测
		XBYTE[ADDR_KEY_WRITE] = scan_data;
		while((XBYTE[ADDR_KEY_READ] & 0x0f) != 0x0f)//检测到0x0f时即找到该列
		{
			col ++;
			scan_data  = scan_data >> 1;
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