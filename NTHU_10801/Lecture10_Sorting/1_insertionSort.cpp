// Insertion sort
// 1. 從第2個index開始分為左右兩邊的list
// 2. 依序從右邊的list中取出數字
// 3. 與左邊已排序好的list相比後插入直到結束
#include <iostream>
using namespace std;

void insertionSort(int* A, const int n){
    for (int i=1; i<n; i++){        // O(n)
        int target = A[i];     
        for (int j=0; j<i; j++){    // O(n)
            // if target < A[j], do insertion
            if (target<A[j])  
            {
                // 將左邊已排序好的list從A[j]後面往後移一格, move sorted list one index back from index A[j]
                for (int k=i; k>j; k--){   
                    A[k] = A[k-1];
                }
                // insert target at A[j]
                A[j] = target;  
                break;
            }
        }   
    }
}

void Print(int* A, const int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
}

int main(){
    const int n = 9;
    // int* A = new int[n];
    // int A[n];
    // int A[n] = {1,2,3,4,5,6,7,8,9};
    // int A[n] = {9,8,7,6,5,4,3,2,1};
    // int A[n] = {5,3,4,7,2,8,6,9,1};
    // int A[n] = {9,8,7,6,5,1,1,1,1};
    int A[n] = {6,1,7,8,9,3,5,4,2};

    insertionSort(A, n);
    Print(A, n);

    return 0;
}