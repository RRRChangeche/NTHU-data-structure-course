#include <iostream>
using namespace std;

// example of algorithm using Binary search and recursive function
// not efficient (just for demo), using while is more efficient
int binarySearch(int* array, const int num, const int left, const int right){
    if (left <= right){ // has more numbers to search
        int middle = (left+right)/2;
        if(num < array[middle]){
            binarySearch(array, num, left, middle-1);
        }
        else if (num > array[middle]){
            binarySearch(array, num, middle+1, right);
        }
        return middle;  // return found index
        
    }
    return -1; // not found
}

// example of recursive function 
int binomialCoefficient(int n, int m){
    if (m > n || n < 1 || m < 1) return 0;
    if (m==0 || n==m) return 1;
    return binomialCoefficient(n-1, m)+binomialCoefficient(n-1, m-1);
}


int main(){
    // binary search 
    int arr[] = {1,2,5,7,9,11,59};
    int size = sizeof(arr)/sizeof(*arr);
    cout << arr << endl;
    cout << *arr << endl;
    cout << "length of array is " << size << endl;
    cout << "found index " << binarySearch(arr, 5, 0, size) << endl;

    // binomial coefficient
    cout << "C(n,m) = " << binomialCoefficient(6,-20) << endl;
    return 0;
}