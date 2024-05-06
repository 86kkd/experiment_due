typedef unsigned char uchar;
typedef unsigned int uint;

extern unsigned char Command; // ָ��Ĵ���
extern unsigned char LCDData; // ���ݼĴ���

extern code unsigned char CCTAB[][32];

void WriteCommandE1();
void WriteCommandE2();
void WriteDataE1();
void WriteDataE2();

#define PD1  61        //  122/2 �ֳ�����������(122x32)

/**������ʾ�ӳ���
Page_: ҳ��ַ 0x00 - 0x03
Column_: �е�ַ 0x00 - 0x80
Code_ : ������ģ���� index
*/ 
void WriteCHN16x16(uchar Page_,uchar Column,uchar Code_)
{
  unsigned char i,j,k;
  i = 0;
  j = 0;
  while(j<2) {
    Command = ((Page_ + j) & 0x03) | 0xb8;   // ����ҳ��ַ
    WriteCommandE1();
    WriteCommandE2();
    k = Column;                   // �е�ֵַ
    while(k < Column + 16){
      if (k < PD1) {              // Ϊ�������ʾ����(E1)
        Command = k;
        WriteCommandE1();         // �����е�ֵַ
        LCDData = CCTAB[Code_][i]; // ȡ������ģ����
        WriteDataE1();            // д��ģ����
      } else{                     // Ϊ�Ұ�����ʾ����(E2)
        Command = k-PD1;
        WriteCommandE2();         // �����е�ֵַ
        LCDData = CCTAB[Code_][i]; // ȡ������ģ����
        WriteDataE2();            // д��ģ����
      };

      i++;
      if( ++k >= PD1 * 2) break;  // �е�ַ�Ƿ񳬳���ʾ��Χ
    } ;
    j++;
  };
}

//Ӣ����ʾ�ӳ���
void WriteCHN8x8(uchar Page_,uchar Column,uchar Code_){
	  unsigned char i,j,k;

		i = 0;
		j = 0;
	
		Command = ((Page_ + j) & 0x03) | 0xb8;   // ����ҳ��ַ
    WriteCommandE1();
    WriteCommandE2();
    k = Column;                   // �е�ֵַ

      if (k < PD1) {              // Ϊ�������ʾ����(E1)
        Command = k;
        WriteCommandE1();         // �����е�ֵַ
        LCDData = CCTAB[Code_][i]; // ȡ������ģ����
        WriteDataE1();            // д��ģ����
      } else{                     // Ϊ�Ұ�����ʾ����(E2)
        Command = k-PD1;
        WriteCommandE2();         // �����е�ֵַ
        LCDData = CCTAB[Code_][i]; // ȡ������ģ����
        WriteDataE2();            // д��ģ����
      };

      i++;
}