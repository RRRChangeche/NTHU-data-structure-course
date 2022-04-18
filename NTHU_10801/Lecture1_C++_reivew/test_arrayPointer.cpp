#include<iostream>

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

    return 0;
}