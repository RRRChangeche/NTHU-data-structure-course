// Ref: https://www.geeksforgeeks.org/heap-sort/?ref=lbp
// https://www.youtube.com/watch?v=MtQL_ll5KhQ
// http://notepad.yehyeh.net/Content/Algorithm/Sort/Heap/Heap.php
// Heap sort
#include <iostream>
using namespace std;

template <class T>
void Heapify(T* A, int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && A[l] > A[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && A[r] > A[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(A[i], A[largest]);
 
        // Recursively heapify the affected sub-tree
        Heapify(A, n, largest);
    }
}

template <class T>
void heapSort(T* A, const int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(A, n, i);

    for (int i=n-1; i>=1; i--)  // Sorting
    {
        swap(A[0], A[i]);          // swap the last node with root
        Heapify(A, i, 0);          // rebuild the A[1:n]
    }
}

void PrintArray(int* A, int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}


int main(){
    const int n = 9;
    // int A[n] = {0,1,2,3,4,5,6,7,8};
    // int A[n] = {9,8,7,6,5,4,3,2,1};
    // int A[n] = {5,3,4,7,2,8,6,9,1};
    // int A[n] = {9,8,7,6,5,1,1,1,1};
    int A[n] = {6,1,7,8,9,3,5,4,2};

    heapSort(A, n);
    PrintArray(A, n);

    return 0;
}