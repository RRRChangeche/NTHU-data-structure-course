// Quick sort
#include <iostream>
using namespace std;

// void swap(int* i, int* j){
//     int tmp = *i;
//     *i = *j;
//     *j = tmp;
// }

// void swap(int i, int j){
//     int tmp = i;
//     i = j;
//     j = tmp;
// }

// void swap(int& i, int& j){
//     int tmp = i;
//     i = j;
//     j = tmp;
// }

void swap(int* i, int* j){
    int* tmp = i;
    i = j;
    j = tmp;
}

int Partition(int* A, int front, int end){
    int pivot = A[front];
    int i = end+1;
    for(int j=front+1; j<end; j++){
        if (A[j] > pivot){
            i--;
            // swap(&A[i], &A[j]);
        }
    }
    i--;
    // swap(&A[i], &A[front]);
    return i;
}

void quickSort(int* A, int front, int end){
    if (front < end){
        int pivot = Partition(A, front, end);
        quickSort(A, front, pivot-1);
        quickSort(A, pivot+1, end);
    }
}

void Print(int* A, const int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
}

int main(){
    const int n = 9;
    // int A[n] = {0,1,2,3,4,5,6,7,8,9};
    // int A[n] = {9,8,7,6,5,4,3,2,1};
    // int A[n] = {5,3,4,7,2,8,6,9,1};
    // int A[n] = {9,8,7,6,5,1,1,1};
    int A[n] = {6,1,7,8,9,3,5,4,2};

    swap(A[0], A[8]);
    // quickSort(A, 0, 9);
    Print(A, n);

    return 0;
}