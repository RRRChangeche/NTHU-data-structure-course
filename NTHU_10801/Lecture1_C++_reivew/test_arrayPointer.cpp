#include <iostream>
#include <map>

using namespace std;

void PrintArray(int* A, const int n){
    for (int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    const int n = 10;
    // int* arr = new int[n];
    // int arr[n];
    // int arr[n] = {0,1,2,3,4,5,6,7,8,9};
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    
    for (int i=0; i<n; i++){
        // arr[i] = i;
        *(arr+i) = i;
    }

    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // std::copy array test
    cout << "std::copy array test" << endl;
    int A[9] = {1,2,3,4,5,6,7,8,9};
    // int B[5];
    int* B = new int[5];
    std::copy(A+2, A+7, B);
    PrintArray(B, 5);

    // swap
    std::swap(A[2], A[7]);
    PrintArray(A, 9);

    // initialize filling with default value
    // https://stackoverflow.com/a/1065800/6887021
    cout << "initialize filling with default value\n";
    // method 1
    int F[10];
    fill_n(F, 10, -1);
    // method 2 (in gcc compiler not here)
    // int F[10] = {[0 ... 9] = -1};
    PrintArray(F, 10); 

    std::map<int, int> map;
    cout << "map[1] " <<  map[1] << endl;

    return 0;
}