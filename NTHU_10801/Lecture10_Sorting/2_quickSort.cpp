// Ref: http://alrightchiu.github.io/SecondRound/comparison-sort-quick-sortkuai-su-pai-xu-fa.html
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
    int pivot = A[front];           // 取第一筆當pivot
    int i = end+1;                  // 設初始i=end+1, 當找到一個數>pivot則i--
    for(int j=end; j>front; j--){   // 搜尋j=end到front+1
        if (A[j] > pivot){          // 如果找到A[j] > pivot則i--, 然後swap(A[i], A[j])
            i--;
            swap(A[i], A[j]);       
        }
    }
    i--;
    swap(A[i], A[front]);           // 最後將pivot替換到i位置
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

    quickSort(A, 0, 9);
    Print(A, n);

    return 0;
}