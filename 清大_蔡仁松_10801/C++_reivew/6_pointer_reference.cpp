#include <iostream>
using namespace std;

int main(){
    // pointer type
    int i = 25;
    int* np = &i;
    cout << np << endl;
    cout << *np << endl;

    // reference type
    int& j = i;
    i = 7; 
    cout << j << endl;

    return 0;
}