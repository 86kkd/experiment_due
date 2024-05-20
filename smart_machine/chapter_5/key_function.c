extern unsigned char Command; // ָ��Ĵ���
extern unsigned char LCDData; // ���ݼĴ���

extern unsigned long int freq;
extern code unsigned char number[][32];

typedef unsigned char uchar;
typedef unsigned int uint;

void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_);
void get_number_input(uchar key);
void display_name (void);
void write_code_16x16(uchar page,uchar col,uchar* str_code);
void Delay500ms();

void Clear();							// ����


void direct_keyfn(unsigned char key)
{

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
		}break;
		
		case 'R':{
			display_name();
		}break;
		default:break;//���������������ʾ

	}
}