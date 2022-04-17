// Ref: http://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html
// Merge sort
#include <iostream>
using namespace std;

#define Max 1e8;

void PrintArray(int* A, int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void merge(int* A, const int left, const int mid, const int right){
    // Seperate A[left:right] part into left and right list 
    const int leftSize = mid-left+2;
    const int rightSize = right-mid+1;
    int* leftA = new int[leftSize];
    int* rightA = new int[rightSize];
    std::copy(A+left, A+mid+1, leftA);
    std::copy(A+mid+1, A+right+1, rightA);
    leftA[leftSize-1]=Max;
    rightA[rightSize-1]=Max;
    int lIdx = 0, rIdx = 0;

    // iterate each A[i] and fill sorted number from leftA/rightA
    for (int i=left; i<=right; i++){
        if (leftA[lIdx] <= rightA[rIdx]){
            A[i] = leftA[lIdx];
            lIdx++;
        }
        else{
            A[i] = rightA[rIdx];
            rIdx++;
        }
    }
}

void mergeSort(int* A, int left, int right){
    if (left < right){
        int mid = (left+right)/2;
        mergeSort(A, left, mid);        // left half
        mergeSort(A, mid+1, right);     // right half
        merge(A, left, mid, right);   
    }
}


int main(){
    const int n = 9;
    // int A[n] = {0,1,2,3,4,5,6,7,8};
    // int A[n] = {9,8,7,6,5,4,3,2,1};
    // int A[n] = {5,3,4,7,2,8,6,9,1};
    // int A[n] = {9,8,7,6,5,1,1,1,1};
    int A[n] = {6,1,7,8,9,3,5,4,2};

    mergeSort(A, 0, 9);
    PrintArray(A, n);

    return 0;
}