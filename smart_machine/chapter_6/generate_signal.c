#include"main.h"

// ���ɷ���
void generateSquareWave() {
    for (;;) { // ����ѭ��
        DAC0832 = 0; // ����DACֵΪ0���͵�ƽ��
        Delay5ms(1); // ��ʱ
        DAC0832 = 255; // ����DACֵΪ255���ߵ�ƽ��
        Delay5ms(1); // ��ʱ
    }
}

// ���������ݲ�
void generateUpSawtoothWave() {
    for (;;) {
        for (uint8_t i = 0; i <= 255; i++) {
            DAC0832 = i;
            Delay5ms(1); // ��ʱ
        }
    }
}

// ���ɷ����ݲ�
void generateDownSawtoothWave() {
    for (;;) {
        for (uint8_t i = 255; i > 0; i--) {
            DAC0832 = i;
            Delay5ms(1); // ��ʱ
        }
    }
}

// �������ǲ�
void generateTriangleWave() {
    for (;;) {
        for (uint8_t i = 0; i < 255; i++) {
            DAC0832 = i;
            Delay5ms(1); // ��ʱ
        }
        for (uint8_t i = 255; i > 0; i--) {
            DAC0832 = i;
            Delay5ms(1); // ��ʱ
        }
    }
}