// Ref: https://medium.com/an%E5%AE%89%E7%9A%84%E5%B0%8F%E5%AD%B8%E7%BF%92%E5%A4%A7%E7%AD%86%E8%A8%98/c-%E5%88%9D%E6%8E%A2-reference-%E8%88%87-pointer-e13ee455ffca
#include<iostream>

using namespace std;

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    // Reference 
    // 便另一個變數的參照(或是別名)
    // 沒有自己的記憶體空間, 所以一定要初始化到一個變數
    int x = 10;
    int& y = x;     // y = reference to x/ alias to x
    // int& y;          // error declaration of reference
    // int& y = 10;     // error declaration of reference

    // Pointer
    // 有自己的記憶體空間, 可以不用初始化(undefined)
    int* z = &x;    // z = pointer to x/ 

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    y = 20;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    *z = 30;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    // swap using function pass by reference
    int a = 10;
    int b = 20;
    swap(a, b);
    cout << a << endl;
    cout << b << endl;

    return 0;
}