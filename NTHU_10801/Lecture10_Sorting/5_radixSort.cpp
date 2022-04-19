// Ref: http://notepad.yehyeh.net/Content/Algorithm/Sort/Radix/Radix.php
// https://www.geeksforgeeks.org/radix-sort/
// https://www.youtube.com/watch?v=7zuGmKfUt7s&ab_channel=BackToBackSWE
// Radix sort
#include <iostream>
using namespace std;

void PrintArray(int* A, int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int getMax(int* A, const int n){
    int max=A[0];
    for (int i=1; i<n; i++){
        if (A[i] > max) max=A[i];
    }
    return max;
}

void countSort(int* A, const int n, int exp){
    int* output = new int[n];
    int count[10] = {0};  // 10 is radix base 
    int i;
    // PrintArray(count , 10);

    // store count of occurences in count[]
    for (int i=0; i<n; i++) 
        count[A[i]/exp %10]++;
    // PrintArray(count , 10);

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    // 將count計數從index 1開始往後累加
    // 得到該位數在output中的位置 (個位數為0~9在output中的位置)
    // for (i = 1; i < 10; i++)
    for (i = 1; i < 10; ++i)
        count[i] += count[i - 1];
    // PrintArray(count , 10);

    // Build the output array in ascending order
    // for i = n-1 to 0 
    // 因為如果0->n-1的話會把之前排序好的較小的值從後面count[]--開始填進output
    for (i = n - 1; i >= 0; i--) {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }
    // PrintArray(output, n);
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; ++i)
        A[i] = output[i];
}

void radixSort(int* A, const int n){
    int max = getMax(A, n);
    for (int exp=1; max/exp>0; exp*=10){ 
        // using count sort
        // first sort with units digit 
        // then tens digit ...
        countSort(A, n, exp);
    }
}



int main(){
    // const int n = 9;
    // int A[n] = {0,1,2,3,4,5,6,7,8};
    // int A[n] = {9,8,7,6,5,4,3,2,1};
    // int A[n] = {5,3,4,7,2,8,6,9,1};
    // int A[n] = {9,8,7,6,5,1,1,1,1};
    // int A[n] = {6,1,7,8,9,3,5,4,2};
    const int n = 15;
    int A[n] = {10,13,15,14,12,11,6,1,7,8,9,3,5,4,2};

    radixSort(A, n);
    PrintArray(A, n);

    return 0;
}