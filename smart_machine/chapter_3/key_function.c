typedef unsigned char uchar;
extern unsigned char Column;
extern unsigned char Page_ ;  // ҳ��ַ�Ĵ��� D1,DO:ҳ��ַ
extern unsigned char Code_ ;  // �ַ�����Ĵ���

extern unsigned char Command; // ָ��Ĵ���
extern unsigned char LCDData; // ���ݼĴ���

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
		case 7://��ʾģʽ0
		{
			Page_ = 0x02;			//������ʾ��
			// Column = 0x00;		//������ʾ��
			Code_ = 0x04;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(7);
			
		}break;
		case 8://��ʾģʽ1
		{
			Page_ = 0x02;
			// Column = 0x10;
			Code_ = 0x05;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(8);
			
		}break;
		case 9://��ʾģʽ2
		{
			Page_ = 0x02;
			// Column = 0x20;
			Code_ = 0x06;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(9);
			
		}break;
		case 10://��ʾģʽ3
		{
			Page_ = 0x02;
			// Column = 0x30;
			Code_ = 0x07;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(10);
			
		}break;
		case ('T')://��ʾģʽ4
		{
			Page_ = 0x02;
			// Column = 0x40;
			Code_ = 0x08;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		case ('R')://��ʾģʽ5
		{
			Page_ = 0x02;
			// Column = 0x50;
			Code_ = 0x09;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		
		//*******************************************
		
		case 4://��ʾģʽ0
		{
			Page_ = 0x00;			//������ʾ��
			// Column = 0x00;		//������ʾ��
			Code_ = 0x0A;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(4);
			
		}break;
		case 5://��ʾģʽ1
		{
			Page_ = 0x00;
			// Column = 0x10;
			Code_ = 0x0B;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(5);
			
		}break;
		case 6://��ʾģʽ2
		{
			Page_ = 0x00;
			// Column = 0x20;
			Code_ = 0x0C;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(6);
			
		}break;
		case 11://��ʾģʽ3
		{
			Page_ = 0x00;
			// Column = 0x30;
			Code_ = 0x0D;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(11);
			
		}break;
		case ('S')://��ʾģʽ4
		{
			Page_ = 0x00;
			// Column = 0x40;
			Code_ = 0x0E;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);

			
		}break;
		case ('M')://��ʾģʽ5
		{
			Page_ = 0x00;
			// Column = 0x50;
			Code_ = 0x0F;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);

			
		}break;
		
		//*******************************************
		
		case 1://��ʾģʽ0
		{
			Page_ = 0x02;			//������ʾ��
			// Column = 0x00;		//������ʾ��
			Code_ = 0x10;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(1);
			
		}break;
		case 2://��ʾģʽ1
		{
			Page_ = 0x02;
			// Column = 0x10;
			Code_ = 0x11;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(2);
			
		}break;
		case 3://��ʾģʽ2
		{
			Page_ = 0x02;
			// Column = 0x20;
			Code_ = 0x12;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(3);
			
		}break;
		case 12://��ʾģʽ3
		{
			Page_ = 0x02;
			// Column = 0x30;
			Code_ = 0x13;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			get_number_input(12);
		}break;
		case ('H')://��ʾģʽ4
		{
			Page_ = 0x02;
			// Column = 0x40;
			Code_ = 0x14;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		case ('L')://��ʾģʽ5
		{
			Page_ = 0x02;
			// Column = 0x50;
			Code_ = 0x15;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		
		//*******************************************
		
		//*******************************************
		
		case 0://��ʾģʽ0
		{
			Page_ = 0x00;			//������ʾ��
			// Column = 0x00;		//������ʾ��
			Code_ = 0x16;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(0);
			
		}break;
		case 15://��ʾģʽ1
		{
			Page_ = 0x00;
			// Column = 0x10;
			Code_ = 0x17;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(15);
			
		}break;
		case 14://��ʾģʽ2
		{
			Page_ = 0x00;
			// Column = 0x20;
			Code_ = 0x18;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(14);
			
		}break;
		case 13://��ʾģʽ3
		{
			Page_ = 0x00;
			// Column = 0x30;
			Code_ = 0x19;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(13);
			
		}break;
		case ('X')://��ʾģʽ4
		{
			Page_ = 0x00;
			// Column = 0x40;
			Code_ = 0x1A;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		case ('N')://��ʾģʽ5
		{
			Page_ = 0x00;
			// Column = 0x50;
			Code_ = 0x1B;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
			
		}break;
		
		
		default:break;//���������������ʾ
		
	}
	
}