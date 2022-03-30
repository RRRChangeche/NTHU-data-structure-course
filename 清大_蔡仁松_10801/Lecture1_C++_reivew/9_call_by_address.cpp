#include <iostream>
using namespace std;

void call_by_address(int* a, int*b){
    cout << "call by address (pointer)" << endl;
    cout << "a: " << a <<endl;
    cout << "b: " << b <<endl;
    *a = 40;
    *b = 50;
    cout << "a: " << a <<endl;
    cout << "b: " << b <<endl;
}

void call_by_reference(int& a, int& b){
    cout << "call by reference" << endl;
    cout << "a: " << a <<endl;
    cout << "b: " << b <<endl; 
    a = 60;
    b = 70;
    cout << "a: " << a <<endl;
    cout << "b: " << b <<endl;
}

int main(){
    int x = 10, y = 20;
    
    call_by_address(&x, &y);
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    call_by_reference(x ,y);
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    return 0;
}