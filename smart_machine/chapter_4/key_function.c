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
void display_name (void);
void display_ADC_Date(uchar ADC_Date);
void delay_ms(unsigned int time);

void keyfn(unsigned char key, uchar ADC_Date)
{
	unsigned char number_index = len_name + len_charcter + len_string;
	unsigned char charcter_index = len_name + len_string;
	unsigned int charcter;
	unsigned int number;
	sbit ADDA=P1^0;			   //   地址A
	sbit ADDB=P1^1;			   //	地址B
	sbit ADDC=P1^2;			   //	地址C
	sbit OE=P1^5;			   //	输出使能
	sbit EOC=P1^6;			   //	 转换标志位
	sbit START_ALE=P1^4;	   //	地址装载，转换启动脚
	
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
		void delay_ms(3000);					// 延时程序	
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
