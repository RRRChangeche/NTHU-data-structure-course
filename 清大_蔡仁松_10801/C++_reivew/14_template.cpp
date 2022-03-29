#include <iostream>
#include <algorithm>
using namespace std;

// function template
template <class T>
T sum(T* data, const int SIZE){
    T sum = 0;
    for (int i=0; i<SIZE; i++){
        sum += data[i];
    }
    return sum;
}

// Define class template Bag
template <class T>
class Bag{
public:
    Bag(int bagCapacity =10);
    ~Bag();

    int Size() const;
    bool IsEmpty() const;
    T& Element() const;

    void push(const T&);
    void pop();

private:
    T* array;
    int capacity;
    int top;
};

// implement template Bag
template <class T>
Bag<T>::Bag(int bagCapacity):capacity(bagCapacity){
    if (capacity < 1) throw "capacity must be > 0";
    array = new T[capacity];
    top = -1;
}

template <class T>
Bag<T>::~Bag(){ delete [] array;}

template <class T>
inline int Bag<T>::Size() const { return top+1; }

template <class T>
inline bool Bag<T>::IsEmpty() const { return Size() == 0; }

template <class T>
inline T& Bag<T>::Element() const {
    if (IsEmpty()) throw "Bag is empty";
    return array[0];    // always return the first element
}

template <class T>
void Bag<T>::push(const T& x){
    // if (capacity == top+1) ChangeSize1D(array, capacity, 2*capacity);
    capacity *= 2;
    cout << "before: " << top << endl;
    array[++top] = x;
    cout << "after: " << top << endl;
}

template <class T>
void Bag<T>::pop(){
    if (IsEmpty()) throw "Bag is empty, cannot delete";
    int deletePos = top/2;  // always delete the middle element
    copy(array+deletePos+1, array+top+1, array+deletePos);
    top--;
}

// define ChangeSIze1D function template
template<class T>
void ChangeSize1D(T* &arr,const int& size,const int& ToSize){
      T* tmp = new T[size];
      tmp = arr;
      arr = new T[ToSize];
      for(int i=0; i< size; ++i){
      arr[i] = tmp[i];
      }
      delete[] tmp;
}


int main(){
    // function template example
    int data1[100];
    fill_n(data1, 100, 1);  //https://stackoverflow.com/a/1065800/6887021
    cout << sum(data1, 100) << endl;

    double data2[100];
    fill_n(data2, 100, 1.1);
    cout << sum(data2, 100) << endl;

    // class template example
    // T is instantiated as int
    Bag<int> bag1;
    bag1.push(1);
    bag1.push(2);
    bag1.push(3);
    cout << bag1.Size() << endl;
    
    return 0;
}