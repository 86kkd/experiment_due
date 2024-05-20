extern unsigned char Column;
extern unsigned char Page_ ;  // ҳ��ַ�Ĵ��� D1,DO:ҳ��ַ
extern unsigned char Code_ ;  // �ַ�����Ĵ���

extern unsigned char Command; // ָ��Ĵ���
extern unsigned char LCDData; // ���ݼĴ���

extern unsigned char len_name;
extern unsigned char len_string;
extern unsigned char len_charcter;
extern unsigned  long int signal_count;

extern unsigned long int freq;
extern code unsigned char number[][32];

typedef unsigned char uchar;
typedef unsigned int uint;

void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_);
void get_number_input(uchar key);
void display_name (void);
void write_code_16x16(uchar page,uchar col,uchar* str_code);
void Delay500ms();

uint add(uint a, uint b);
uint subtract(uint a, uint b);
uint multiply(uint a, uint b);
uint divide(uint a, uint b);
uint calculate_result(uint (*functionPtr)( uint a ,uint b));

uint (*functionPtr)( uint a ,uint b);

void Clear();							// ����


void direct_keyfn(unsigned char key)
{
unsigned char number_index = len_name + len_charcter + len_string;

	int display_bit;
	unsigned long int tem_freq=freq;
	int i;
	switch(key)
	{
		//��ʾģʽ0
		case 15:{
			Clear();
			for (i=7;i>0;i--){
				display_bit = tem_freq%10;
				write_code_16x16(0x03,(0x01+i-2)<<4,&number[display_bit]);
				tem_freq/=10;
				if(tem_freq==0)break;
			}	
		Delay500ms();
		}break;
		
		case 'R':{
			display_name();
			Delay500ms();
		}break;
		default:break;//���������������ʾ

	}
}
void precess_keyfn(unsigned char key_num)
{
	unsigned char number_index = len_name + len_charcter + len_string;

	int display_bit;
	unsigned long int tem_freq=freq;
	int i;
	switch(key_num)
	{
		case 7://��ʾģʽ0
		{
			//Page_ = 0x02;			//������ʾ��
			// Column = 0x00;		//������ʾ��

			for (i=7;i>0;i--){
				display_bit = tem_freq/10;
				write_code_16x16(0x03,(0x01+i)<<4,&number[display_bit]);
				tem_freq/=10;
				if(tem_freq==0)break;
			}
			Code_ = 7 + number_index;
			WriteCHN16x16(Page_=0x02 ,Column=0x00 ,Code_);
            get_number_input(7);
			
		}break;
		case 8://��ʾģʽ1
		{
			Page_ = 0x02;
			// Column = 0x10;
			Code_ = 8 + number_index;
			WriteCHN16x16(Page_=0x02 ,Column=0x10 ,Code_);
            get_number_input(8);
			
		}break;
		case 9://��ʾģʽ2
		{
			Page_ = 0x02;
			// Column = 0x20;
			Code_ = 9 + number_index;
			WriteCHN16x16(Page_ ,Column=0x20 ,Code_);
            get_number_input(9);
			
		}break;
		case 10://��ʾģʽ3
		{
			Page_ = 0x02;
			// Column = 0x30;
			Code_ = 10 + number_index;
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
			Code_ = 4 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(4);
			
		}break;
		case 5://��ʾģʽ1
		{
			Page_ = 0x00;
			// Column = 0x10;
			Code_ = 5 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(5);
			
		}break;
		case 6://��ʾģʽ2
		{
			Page_ = 0x00;
			// Column = 0x20;
			Code_ = 6 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(6);
			
		}break;
		case 11://��ʾģʽ3
		{
			Page_ = 0x00;
			// Column = 0x30;
			Code_ = 11 + number_index;
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
			Code_ = 1 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(1);
			
		}break;
		case 2://��ʾģʽ1
		{
			Page_ = 0x02;
			// Column = 0x10;
			Code_ = 2 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(2);
			
		}break;
		case 3://��ʾģʽ2
		{
			Page_ = 0x02;
			// Column = 0x20;
			Code_ = 3 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(3);
			
		}break;
		case 12://��ʾģʽ3
		{
			Page_ = 0x02;
			// Column = 0x30;
			Code_ = 12 + number_index;
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
			Code_ = 0 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(0);
			
		}break;
		case 15://��ʾģʽ1
		{
			for (i=7;i>0;i--){
				display_bit = tem_freq/10;
				write_code_16x16(0x03,(0x01+i)<<4,&number[display_bit]);
				tem_freq/=10;
				if(tem_freq==0)break;
			}
			
		}break;
		case 14://��ʾģʽ2
		{
			Page_ = 0x00;
			// Column = 0x20;
			Code_ = 14 + number_index;
			WriteCHN16x16(Page_ ,Column=0x00 ,Code_);
            get_number_input(14);
			
		}break;
		case 13://��ʾģʽ3
		{
			Page_ = 0x00;
			// Column = 0x30;
			Code_ = 13 + number_index;
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