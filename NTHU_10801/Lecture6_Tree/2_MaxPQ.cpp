// Ref:
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Maximun Priority Queue (implememt by Max Heap)
template <class T>
class MaxPQ
{
public:
    MaxPQ() { 
        heapSize = 0;
        heap = new T();
    };
    ~MaxPQ() {};

    bool isEmpty();         // check if PQ is empty
    T& Top() const;         // return reference to the maximun element
    void Push(const T&);    // Add element to the PQ
    void Pop();             // Delete element with maximun priority
    void Print();           // Print the Heap

private:
    T* heap;
    int heapSize;
    int capacity;
};

template<class T>
bool MaxPQ<T>::isEmpty(){
    return heapSize < 1;
}

template <class T>
T& MaxPQ<T>::Top() const{
    cout << "Top element is: " << to_string(heap[1]) << endl;
    return heap[1];
}

template <class T>
void MaxPQ<T>::Push(const T& e){
    // Insert r into max heap
    int currentNode = ++heapSize;

    while(currentNode != 1 && heap[currentNode/2] < e){
        //  swap with parent node
        heap[currentNode] = heap[currentNode/2];
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template <class T>
void MaxPQ<T>::Pop(){
    if (isEmpty()) cout << "Heap is empty!" << endl;
    heap[1].~T();
    T lastNode = heap[heapSize--];

    // trickle down
    int currentNode = 1;    // root
    int child = 2;          // a child of currentNode 
    while(child <= heapSize){
        // set child to the larger child of currentNode
        if (child < heapSize && heap[child] < heap[child+1]) child++;

        // can we put lastNode into heap?
        if (lastNode >= heap[child]) break;

        // if not, resorting not finish
        heap[currentNode] = heap[child];     // move child up
        currentNode = child; child *= 2;    // move down level
    }
    // put lastNode into heap
    heap[child/2] = lastNode;
}

template <class T>
void MaxPQ<T>::Print(){
    int level = ceil(log2(heapSize+1)); // max heapSize for given level is 2^k-1
    cout << "level: " << level << endl;
    for (int i = 1; i <= level; i++){
        string line;
        // int n = level-pow(2,i-1);
        // while (n>0) {line+="     "; n--;}

        for (int j = pow(2, i-1); j < pow(2, i) && j <= heapSize; j++){
            line += to_string(heap[j]) + " ";
        }
        cout << line << endl;
    }
}


int main () {
    MaxPQ<int> maxpq;

    maxpq.Push(5);
    maxpq.Push(4);
    maxpq.Push(3);
    maxpq.Push(2);
    maxpq.Push(1);

    maxpq.Pop();
    maxpq.Print();
    maxpq.Top();
    maxpq.Pop();
    maxpq.Pop();
    maxpq.Print();
    maxpq.Top();

    return 0;
}