#include"main.h"

uchar add(uchar a, uchar b);
uchar subtract(uchar a, uchar b);
uchar multiply(uchar a, uchar b);
uchar divide(uchar a, uchar b);

uchar input_number [2] ={0};
uchar i = 0;

void get_number_input(uchar key)
{
    input_number[i] = key;
    i = ++i%2;
}


uchar calculate_result(uchar (*functionPtr)( uchar a ,uchar b))
{
    return functionPtr(input_number[0], input_number[1]);
}

// 一位正整数的加法
uchar add(uchar a, uchar b) {
    return a + b;
}

// 一位正整数的减法
uchar subtract(uchar a, uchar b) {
    if (a < b) {
        return b - a;
    }
    return a - b;
}

// 一位正整数的乘法
uchar multiply(uchar a, uchar b) {
    return a * b;
}

// 一位正整数的除法
uchar divide(uchar a, uchar b) {
    if (b == 0) {
        return 0;
    }
    return a / b;
}