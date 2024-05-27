#include "main.h"

#define PD1  61        //  122/2 �ֳ�����������(122x32)

/**������ʾ�ӳ���
Page_: ҳ��ַ 0x00 - 0x03
Column_: �е�ַ 0x00 - 0x80
Code_ : ������ģ���� index
*/ 
void write_code_16x16(uchar page,uchar col,uchar* str_code) {
  unsigned char i,j,k;
  i = 0;
  j = 0;
  while(j<2) {
    Command = ((page + j) & 0x03) | 0xb8;   // ����ҳ��ַ
    WriteCommandE1();
    WriteCommandE2();
    k = col;                   // �е�ֵַ
    while(k < col + 16){
      if (k < PD1) {              // Ϊ�������ʾ����(E1)
        Command = k;
        WriteCommandE1();         // �����е�ֵַ
        LCDData = str_code[i]; // ȡ������ģ����
        WriteDataE1();            // д��ģ����
      } else{                     // Ϊ�Ұ�����ʾ����(E2)
        Command = k-PD1;
        WriteCommandE2();         // �����е�ֵַ
        LCDData = str_code[i]; // ȡ������ģ����
        WriteDataE2();            // д��ģ����
      };

      i++;
      if( ++k >= PD1 * 2) break;  // �е�ַ�Ƿ񳬳���ʾ��Χ
    } ;
    j++;
  };
}

//Ӣ����ʾ�ӳ���
void write_code_8x8(uchar page,uchar col,uchar* str_code){
	  unsigned char i,j,k;

		i = 0;
		j = 0;
	
		Command = ((page + j) & 0x03) | 0xb8;   // ����ҳ��ַ
    WriteCommandE1();
    WriteCommandE2();
    k = col;                   // �е�ֵַ

      if (k < PD1) {              // Ϊ�������ʾ����(E1)
        Command = k;
        WriteCommandE1();         // �����е�ֵַ
        LCDData = str_code[i]; // ȡ������ģ����
        WriteDataE1();            // д��ģ����
      } else{                     // Ϊ�Ұ�����ʾ����(E2)
        Command = k-PD1;
        WriteCommandE2();         // �����е�ֵַ
        LCDData = str_code[i]; // ȡ������ģ����
        WriteDataE2();            // д��ģ����
      };
      i++;
}