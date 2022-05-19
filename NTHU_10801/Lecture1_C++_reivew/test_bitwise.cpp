// Reference : https://web.ntnu.edu.tw/~algo/Bit.html
#include <iostream>
#include<bitset>
using namespace std;

void add(int& bitset, int element)
{
    bitset |= (1 << element);
}

void remove(int& bitset, int element)
{
    bitset &= ~(1 << element);
}

// __builtin_popcount
// 僅適用32位元無號數
unsigned int count_1_bit(unsigned int x)
{
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
    return x;
}

// 僅適用32位元無號數
unsigned int bit_reverse(unsigned int x)
{
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >> 16) & 0x0000ffff) | ((x << 16) & 0xffff0000);
    return x;
}

// 注意：比直接交換還要慢。
void swap(int& x, int& y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

int main(){
    int n = 0b1010111100011100;
    cout << n << endl;

    // bitwise operation
    // 由右往左看n的每一個位元。
    int c = 0;
    for (int i=0; i<32; ++i)    // int變數有32個位元
        if (n & (1 << i))
            c++;
    cout << c << endl;

    // 一樣是由右往左，但是每次都刪掉n的最右位元。
    c = 0;
    for (; n; n>>=1)
        if (n & 1)
            c++;
    cout << c << endl;

    // unsigned 左移右移
    // 若需用到最左邊位元則需要用unsigned
    uint32_t ui = 0b1010111100011100;
    ui >>= 1;
    n >>= 1;
    cout << ui << endl;
    cout << n << endl;

    // Bit Shift Multiplication （自然數乘法）
    n = 5;  
    // n >>= 1; // 等同 n /= 2
    n <<= 1;    // 等同 n = n*2
    // ...........101 = 5
    // n >> 1 = ..010 = 2
    // n << 1 = .1010 = 10
    cout << n << endl;

    // Bitset
    add(n, 5);
    cout << n << endl;

    // Number of 1 Bits （計算有幾個位元是 1 ）
    // 方法一
    c = 0;
    for (int i=0; i<32; ++i)    // int變數有32個位元
        if (n & (1 << i))
            c++;
    cout << c << endl;
    // 方法二
    int x = count_1_bit(n);
    cout << x << endl;

    // Swap
    int a = 0b101;  // 5
    int b = 0b001;  // 1
    swap(a, b);
    // a = a ^ b = 101 ^ 001 = 100
    // b = a ^ b = 100 ^ 001 = 101
    // a = a ^ b = 100 ^ 101 = 001
    cout << a << " " << b << endl;

    // int to binary array
    int value = 6;  // assuming a 32 bit int
    const int bits = 3;
    // 方法一 
    // https://stackoverflow.com/questions/14104208/convert-integer-to-binary-and-store-it-in-an-integer-array-of-specified-sizec
    int b_arr[bits];
    for (int i=0; i<bits; i++) {
        b_arr[i] = (value >> i) & 1;
        // i=0
        // 110 >> 0 = 110 & 001 = 000
        // i=2
        // 110 >> 1 = 011 & 001 = 001
        // i=3
        // 110 >> 2 = 001 & 001 = 001
        // b_arr = [0, 1, 1] = 0b110
    }
    for (int i=0; i<bits; i++) cout << b_arr[i];
    cout << endl;
    // 方法二
    bitset<3> A=value;  //A will hold the binary representation of N 
    for (int i=0; i<bits; i++){
        cout << A[bits-i-1];
    }
    cout << endl;
    
    return 0;
}

