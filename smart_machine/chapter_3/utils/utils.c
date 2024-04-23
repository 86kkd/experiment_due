typedef unsigned char uchar;
typedef unsigned int uint;

extern xdata uchar CWADD1 ;   // дָ������ַ(E1)
extern xdata uchar DWADD1 ;   // д��ʾ���ݵ�ַ(E1)
extern xdata uchar CRADD1 ;   // ��״̬�ֵ�ַ(E1)
extern xdata uchar DRADD1 ;   // ����ʾ���ݵ�ַ(E1)

extern xdata uchar CWADD2 ;   // дָ������ַ(E2)
extern xdata uchar DWADD2 ;   // д��ʾ������ַ(E2)
extern xdata uchar CRADD2 ;   // ��״̬�ֵ�ַ(E2)
extern xdata uchar DRADD2 ;   // ����ʾ���ݵ�ַ(E2)


extern uchar Column;
extern uchar Page_ ;  // ҳ��ַ�Ĵ��� D1,DO:ҳ��ַ
extern uchar Code_ ;  // �ַ�����Ĵ���

extern uchar Command; // ָ��Ĵ���
extern uchar LCDData; // ���ݼĴ���



// 1.дָ������ӳ���(E1)
void WriteCommandE1()
{
  while(CRADD1 & 0x80);
  CWADD1 = Command;
}

// 2.д��ʾ�����ӳ���(E1)
void WriteDataE1()
{
  while(CRADD1 & 0x80);
  DWADD1 = LCDData;
}

// 3.����ʾ�����ӳ���(E1)
void ReadDataE1()
{
  while(CRADD1 & 0x80);
  LCDData = DRADD1;
}

// 4.дָ������ӳ���(E2)
void WriteCommandE2()
{
  while(CRADD2 & 0x80);
  CWADD2 = Command;
}

// 5.д��ʾ�����ӳ���(E2)
void WriteDataE2()
{
  while(CRADD2 & 0x80);
  DWADD2 = LCDData;
}

// 6.����ʾ�����ӳ���(E2)
void ReadDataE2()
{
  while(CRADD2 & 0x80);
  LCDData = DRADD2;
}

// ��ʼ������
void Init()
{
  Command = 0xe2;
  WriteCommandE1();
  WriteCommandE2();

  Command = 0xa4;
  WriteCommandE1();
  WriteCommandE2();

  Command = 0xa9;
  WriteCommandE1();
  WriteCommandE2();

  Command = 0xa0;
  WriteCommandE1();
  WriteCommandE2();

  Command = 0xc0;
  WriteCommandE1();
  WriteCommandE2();

  Command = 0xaf;
  WriteCommandE1();
  WriteCommandE2();
}

// ����
void Clear()
{
  uchar i,j;

  i = 0;
  do {

    Command = (i + 0xb8); // ҳ��ַ����
    WriteCommandE1();
    WriteCommandE2();

    Command = 0x00;      // �е�ַ����Ϊ"0"
    WriteCommandE1();
    WriteCommandE2();

    j = 0x50;            // һҳ�� 80���ֽ�
    do {
      LCDData = 0x00;    // ��ʾ����Ϊ"0"
      WriteDataE1();
      WriteDataE2();
    }while(--j !=0);     // ҳ���ֽ�����ѭ��

  }while(++i !=4);       // ҳ��ַ�ݴ�����һ
                         // ��ʾ������ѭ��
}
void Delay5ms()		//@12.000MHz
{
	uchar i, j;

	i = 10;
	j = 183;
	do
	{
		while (--j);
	} while (--i);
}