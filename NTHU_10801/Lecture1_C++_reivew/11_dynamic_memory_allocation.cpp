#include <iostream>
using namespace std;

int main(){
    int* y = new int;
    cout << y << endl;
    delete y;
    cout << y << endl;

    // allocate an int array
    int* data = new int[10];
    cout << data << endl;
    delete [] data;
    cout << data << endl;

    return 0;
}