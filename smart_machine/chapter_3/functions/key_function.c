typedef unsigned char uchar;
extern unsigned char Column;
extern unsigned char Page_ ;  // 页地址寄存器 D1,DO:页地址
extern unsigned char Code_ ;  // 字符代码寄存器

extern unsigned char Command; // 指令寄存器
extern unsigned char LCDData; // 数据寄存器

void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_);
void get_number_input(uchar key);

uchar add(uchar a, uchar b);
uchar subtract(uchar a, uchar b);
uchar multiply(uchar a, uchar b);
uchar divide(uchar a, uchar b);
uchar calculate_result(uchar *calculate_fun);

uchar (*functionPtr)( uchar a ,uchar b);
// functionPtr = add;
// calculate_result(functionPtr);


void precess_keyfn(unsigned char key_num)
{
	switch(key_num)
	{
		case 7://显示模式0
		{
			Page_ = 0x02;			//设置显示行
			// Column = 0x00;		//设置显示列
			Code_ = 0x04;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(7);
			
		}break;
		case 8://显示模式1
		{
			Page_ = 0x02;
			// Column = 0x10;
			Code_ = 0x05;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(8);
			
		}break;
		case 9://显示模式2
		{
			Page_ = 0x02;
			// Column = 0x20;
			Code_ = 0x06;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(9);
			
		}break;
		case 10://显示模式3
		{
			Page_ = 0x02;
			// Column = 0x30;
			Code_ = 0x07;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(10);
			
		}break;
		case ('T')://显示模式4
		{
			Page_ = 0x02;
			// Column = 0x40;
			Code_ = 0x08;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		case ('R')://显示模式5
		{
			Page_ = 0x02;
			// Column = 0x50;
			Code_ = 0x09;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		
		//*******************************************
		
		case 4://显示模式0
		{
			Page_ = 0x00;			//设置显示行
			// Column = 0x00;		//设置显示列
			Code_ = 0x0A;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(4);
			
		}break;
		case 5://显示模式1
		{
			Page_ = 0x00;
			// Column = 0x10;
			Code_ = 0x0B;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(5);
			
		}break;
		case 6://显示模式2
		{
			Page_ = 0x00;
			// Column = 0x20;
			Code_ = 0x0C;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(6);
			
		}break;
		case 11://显示模式3
		{
			Page_ = 0x00;
			// Column = 0x30;
			Code_ = 0x0D;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(11);
			
		}break;
		case ('S')://显示模式4
		{
			Page_ = 0x00;
			// Column = 0x40;
			Code_ = 0x0E;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);

			
		}break;
		case ('M')://显示模式5
		{
			Page_ = 0x00;
			// Column = 0x50;
			Code_ = 0x0F;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);

			
		}break;
		
		//*******************************************
		
		case 1://显示模式0
		{
			Page_ = 0x02;			//设置显示行
			// Column = 0x00;		//设置显示列
			Code_ = 0x10;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(1);
			
		}break;
		case 2://显示模式1
		{
			Page_ = 0x02;
			// Column = 0x10;
			Code_ = 0x11;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(2);
			
		}break;
		case 3://显示模式2
		{
			Page_ = 0x02;
			// Column = 0x20;
			Code_ = 0x12;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(3);
			
		}break;
		case 12://显示模式3
		{
			Page_ = 0x02;
			// Column = 0x30;
			Code_ = 0x13;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			get_number_input(12);
		}break;
		case ('H')://显示模式4
		{
			Page_ = 0x02;
			// Column = 0x40;
			Code_ = 0x14;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		case ('L')://显示模式5
		{
			Page_ = 0x02;
			// Column = 0x50;
			Code_ = 0x15;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		
		//*******************************************
		
		//*******************************************
		
		case 0://显示模式0
		{
			Page_ = 0x00;			//设置显示行
			// Column = 0x00;		//设置显示列
			Code_ = 0x16;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(0);
			
		}break;
		case 15://显示模式1
		{
			Page_ = 0x00;
			// Column = 0x10;
			Code_ = 0x17;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(15);
			
		}break;
		case 14://显示模式2
		{
			Page_ = 0x00;
			// Column = 0x20;
			Code_ = 0x18;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(14);
			
		}break;
		case 13://显示模式3
		{
			Page_ = 0x00;
			// Column = 0x30;
			Code_ = 0x19;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(13);
			
		}break;
		case ('X')://显示模式4
		{
			Page_ = 0x00;
			// Column = 0x40;
			Code_ = 0x1A;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		case ('N')://显示模式5
		{
			Page_ = 0x00;
			// Column = 0x50;
			Code_ = 0x1B;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		
		
		default:break;//其余情况不更新显示
		
	}
	
}