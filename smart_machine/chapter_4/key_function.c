extern unsigned char Column;
extern unsigned char Page_ ;  // ҳ��ַ�Ĵ��� D1,DO:ҳ��ַ
extern unsigned char Code_ ;  // �ַ�����Ĵ���

extern unsigned char Command; // ָ��Ĵ���
extern unsigned char LCDData; // ���ݼĴ���

extern unsigned char len_name;
extern unsigned char len_string;
extern unsigned char len_charcter;

typedef unsigned char uchar;
typedef unsigned int uint;

void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_);
void display_name (void);
void display_ADC_Date(uchar ADC_Date);
void delay_ms(unsigned int time);

void keyfn(unsigned char key, uchar ADC_Date)
{
	unsigned char number_index = len_name + len_charcter + len_string;
	unsigned char charcter_index = len_name + len_string;
	unsigned int charcter;
	unsigned int number;
	sbit ADDA=P1^0;			   //   ��ַA
	sbit ADDB=P1^1;			   //	��ַB
	sbit ADDC=P1^2;			   //	��ַC
	sbit OE=P1^5;			   //	���ʹ��
	sbit EOC=P1^6;			   //	 ת����־λ
	sbit START_ALE=P1^4;	   //	��ַװ�أ�ת��������
	
	uint col;
	
	switch(key){
	case 'A': {	// = 
		display_name();
		}
		break;
	case 'B':{

		ADDA=0;
		ADDB=0;
		ADDC=0;
		ADC_Date = ADC_CONVERT(START_ALE,EOC,OE);
	    ADC_Date = ADC_Date/51;
		display_ADC_Date(ADC_Date);
		}
		break;
	case 'C':{
		ADDA=0;
		ADDB=0;
		ADDC=1;
		ADC_Date = ADC_CONVERT(START_ALE,EOC,OE);
	    ADC_Date = ADC_Date/51;
		display_ADC_Date(ADC_Date);
		}
		break;
	case 'D':{
		ADDA=0;
		ADDB=0;
		ADDC=1;
		ADC_Date = ADC_CONVERT(START_ALE,EOC,OE);
	    ADC_Date = ADC_Date/51;
	    display_ADC_Date(ADC_Date);
		void delay_ms(3000);					// ��ʱ����	
		ADDA=0;
		ADDB=0;
		ADDC=1;
		ADC_Date = ADC_CONVERT(START_ALE,EOC,OE);
	    ADC_Date = ADC_Date/51;
		display_ADC_Date(ADC_Date);
		}
	default:{
		}
		break;
	}

}
