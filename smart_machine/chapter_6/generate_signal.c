#include"main.h"

// 生成方波
void generateSquareWave() {
    for (;;) { // 无限循环
        DAC0832 = 0; // 设置DAC值为0（低电平）
        Delay5ms(1); // 延时
        DAC0832 = 255; // 设置DAC值为255（高电平）
        Delay5ms(1); // 延时
    }
}

// 生成正向锯齿波
void generateUpSawtoothWave() {
    for (;;) {
        for (uint8_t i = 0; i <= 255; i++) {
            DAC0832 = i;
            Delay5ms(1); // 延时
        }
    }
}

// 生成反向锯齿波
void generateDownSawtoothWave() {
    for (;;) {
        for (uint8_t i = 255; i > 0; i--) {
            DAC0832 = i;
            Delay5ms(1); // 延时
        }
    }
}

// 生成三角波
void generateTriangleWave() {
    for (;;) {
        for (uint8_t i = 0; i < 255; i++) {
            DAC0832 = i;
            Delay5ms(1); // 延时
        }
        for (uint8_t i = 255; i > 0; i--) {
            DAC0832 = i;
            Delay5ms(1); // 延时
        }
    }
}