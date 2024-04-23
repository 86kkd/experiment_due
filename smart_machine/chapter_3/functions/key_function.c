extern unsigned char Command; // Ö¸Áî¼Ä´æÆ÷
extern unsigned char LCDData; // Êı¾İ¼Ä´æÆ÷

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

void Clear();							// ÇåÆÁ
// functionPtr = add;
// calculate_result(functionPtr);

uint (*fun())( uint a ,uint b) function_map(uchar key) {
	switch(key){
		case 10:return add;break;
		case 11:return subtract;break;
		case 12:return multiply;break;
		case 13:return divide;break
	}
}

void direct_keyfn(unsigned char key, uint *num_input)
{
	uchar number_index = len_name + len_charcter + len_string;
	uchar charcter_index = len_name + len_string;
	uint charcter;
	uint number;
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
		case 'R':{ // clear
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
		
	}else if (num_input_n == 1){
		functionPtr = function_map(uchar key);
	}
	else{
		number = key + number_index;
		col = num_input_n <<4;
		WriteCHN16x16(Page_=0x00 ,col ,number);
	}
}

