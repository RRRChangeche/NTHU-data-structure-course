// Ref: http://users.cis.fiu.edu/~weiss/Deltoid/vcstl/templatess
#include <iostream>
using namespace std;

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

// Define class template
template <class T>
class Stack{
public:
    // Constructor
    Stack(int capacity = 10);

    bool isEmpty() const;   // check if stack is empty
    T& Top() const;    // return the top element 
    void Push(const T& item);   // Insert a new element at top
    void Pop(); // delete one element from top
    void Print();

private:
    T* stack;
    int top;    // init -1
    int capacity;
};

// constructor
template <class T>
Stack<T>::Stack(int c){
    capacity = c;
    stack = new T[capacity];
    top = -1;
}

// member function
template <class T>
bool Stack<T>::isEmpty() const{
    if(top != -1) return false;
    else return true;
}

template <class T>
T& Stack<T>::Top() const{
    return top;
} 

template <class T>
void Stack<T>::Push(const T& item){
    // add item to stack
    if (top == capacity-1){
        ChangeSize1D(stack, capacity, 2*capacity);
        capacity *= 2;
    }
    stack[++top] = item;
}

template <class T>
void Stack<T>::Pop(){
    if (isEmpty()) throw "Stack is empty, cannot delete";
    stack[top--].~T();  // delete the element
}

template <class T>
void Stack<T>::Print(){
    for (int i=0; i<top+1; i++){
        cout << stack[i] << " ";
    }
    cout << endl;
}


int main () {
    // Instantiating template class
    typedef Stack<int> IntStack;
    IntStack s(5);

    // Push
    s.Push(10);
    s.Print();
    s.Push(11);
    s.Push(12);
    s.Push(13);
    s.Push(14);
    s.Print();
    s.Push(15);
    s.Print();

    // pop example
    s.Pop();
    s.Print();

    return 0;
}