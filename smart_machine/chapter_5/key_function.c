extern unsigned char Column;
extern unsigned char Page_ ;  // 页地址寄存器 D1,DO:页地址
extern unsigned char Code_ ;  // 字符代码寄存器

extern unsigned char Command; // 指令寄存器
extern unsigned char LCDData; // 数据寄存器

extern unsigned char len_name;
extern unsigned char len_string;
extern unsigned char len_charcter;

typedef unsigned char uchar;
typedef unsigned int uint;

void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_);
void get_number_input(uchar key);

uint add(uint a, uint b);
uint subtract(uint a, uint b);
uint multiply(uint a, uint b);
uint divide(uint a, uint b);
uint calculate_result(uint (*functionPtr)( uint a ,uint b));

uint (*functionPtr)( uint a ,uint b);

void Clear();							// 清屏


void direct_keyfn(unsigned char key, uint *num_input)
{
	unsigned char number_index = len_name + len_charcter + len_string;
	unsigned char charcter_index = len_name + len_string;
	unsigned int charcter;
	unsigned int number;
	uint num_input_n = *num_input;
	uint result = 0;
	
	uint col;
	
		//number = key + number_index;
		//col = num_input_n <<4;
		//WriteCHN16x16(Page_=0x00 ,col ,number);
	
	if(num_input_n == 3){
		
		switch(key){
		case 'H': {	// = 
			col = num_input_n << 4;
			WriteCHN16x16(Page_=0x00 ,col ,11);
			col = (num_input_n+1) << 4;
			result = calculate_result(functionPtr);
			WriteCHN16x16(Page_=0x00 ,col ,result);
			}
			break;
		case 'R':{
			col = --(*num_input) << 4;
			WriteCHN16x16(Page_=0x00 ,col ,28);
			}
			break;
		default:{
			charcter = key + charcter_index;
			col = num_input_n <<4;
			WriteCHN16x16(Page_=0x00 ,col ,number);
			}
			break;
		}
		
	}else if (num_input_n == 1){;
	}
	else{
		number = key + number_index;
		col = num_input_n <<4;
		WriteCHN16x16(Page_=0x00 ,col ,number);
	}
}

void precess_keyfn(unsigned char key_num)
{
	unsigned char number_index = len_name + len_charcter + len_string;
	switch(key_num)
	{
		case 7://显示模式0
		{
			//Page_ = 0x02;			//设置显示行
			// Column = 0x00;		//设置显示列
			Code_ = 7 + number_index;
			WriteCHN16x16(Page_=0x02 ,Column=0x00 ,Code_);
            get_number_input(7);
			
		}break;
		case 8://显示模式1
		{
			Page_ = 0x02;
			// Column = 0x10;
			Code_ = 8 + number_index;
			WriteCHN16x16(Page_=0x02 ,Column=0x10 ,Code_);
            get_number_input(8);
			
		}break;
		case 9://显示模式2
		{
			Page_ = 0x02;
			// Column = 0x20;
			Code_ = 9 + number_index;
			WriteCHN16x16(Page_ ,Column=0x20 ,Code_);
            get_number_input(9);
			
		}break;
		case 10://显示模式3
		{
			Page_ = 0x02;
			// Column = 0x30;
			Code_ = 10 + number_index;
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
			Code_ = 4 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(4);
			
		}break;
		case 5://显示模式1
		{
			Page_ = 0x00;
			// Column = 0x10;
			Code_ = 5 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(5);
			
		}break;
		case 6://显示模式2
		{
			Page_ = 0x00;
			// Column = 0x20;
			Code_ = 6 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(6);
			
		}break;
		case 11://显示模式3
		{
			Page_ = 0x00;
			// Column = 0x30;
			Code_ = 11 + number_index;
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
			Code_ = 1 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(1);
			
		}break;
		case 2://显示模式1
		{
			Page_ = 0x02;
			// Column = 0x10;
			Code_ = 2 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(2);
			
		}break;
		case 3://显示模式2
		{
			Page_ = 0x02;
			// Column = 0x20;
			Code_ = 3 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(3);
			
		}break;
		case 12://显示模式3
		{
			Page_ = 0x02;
			// Column = 0x30;
			Code_ = 12 + number_index;
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
			Code_ = 0 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(0);
			
		}break;
		case 15://显示模式1
		{
			Page_ = 0x00;
			// Column = 0x10;
			Code_ = 15 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(15);
			
		}break;
		case 14://显示模式2
		{
			Page_ = 0x00;
			// Column = 0x20;
			Code_ = 14 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(14);
			
		}break;
		case 13://显示模式3
		{
			Page_ = 0x00;
			// Column = 0x30;
			Code_ = 13 + number_index;
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