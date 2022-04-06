// Ref: http://users.cis.fiu.edu/~weiss/Deltoid/vcstl/templates
// http://alrightchiu.github.io/SecondRound/queue-yi-arrayshi-zuo-queue.html
#include <iostream>
using namespace std;

// Define class template
template <class T>
class CircularQueue{
public:
    // Constructor
    CircularQueue(int capacity = 5);
    ~CircularQueue();

    bool isEmpty() const;   // check if CircularQueue is empty
    bool isFull() const;    // check if CircularQueue is full
    T& Front() const;    // return the top element 
    T& Rear() const;    // return the top element 
    void Push(const T& item);   // Insert a new element at top
    void Pop(); // delete one element from top
    void Print();
    int getSize();
    int getCapcity();

private:
    T* queue;
    int front, rear;    // init -1 for sequential array, init 0 for circular array
    int capacity;

    // private member function
    void ChangeSize1D(T*&, const int& ,const int&);
};

// constructor
template <class T>
CircularQueue<T>::CircularQueue(int c){
    capacity = c;
    queue = new T[capacity];
    // front = rear = -1;   // for swquential array
    front = rear = 0;   // for circular array
}

template <class T>
CircularQueue<T>::~CircularQueue(){
    delete [] queue;
}

// member function
template <class T>
bool CircularQueue<T>::isEmpty() const { return front==rear; }

template <class T>
bool CircularQueue<T>::isFull() const { return (front+1)%capacity == rear; }

template <class T>
T& CircularQueue<T>::Front() const {
    if (isEmpty()) {
        cout << "CircularQueue is empty!" << endl;
    }
    return queue[(front+1)%capacity];
}

template <class T>
T& CircularQueue<T>::Rear() const {
    if (isEmpty()) {
        cout << "CircularQueue is empty!" << endl;
    }
    return queue[rear];
}

template <class T>
void CircularQueue<T>::Push(const T& item){ // add item at rear of queue, 一開始從index=1開始填
    if(isFull())    // queue is going to full, double the capacity
    {
        ChangeSize1D(queue, capacity, 2*capacity);
    }
    rear = (rear+1) % capacity;
    queue[rear] = item;
    cout << "Push " << queue[rear] << " into the queue" << endl;
}

template <class T>
void CircularQueue<T>::Pop(){ // delete front element from queue
    if (isEmpty()) {
        cout << "CircularQueue is empty!" << endl;
    }
    front = (front+1) % capacity;
    // queue[front].~T();
    cout << "Pop " << queue[front] << " from the queue" << endl;
}

template <class T>
int CircularQueue<T>::getCapcity(){
    return capacity;
}

template <class T>
void CircularQueue<T>::Print(){
    cout << "queue: ";
    if (front < rear){
        for (int i=front+1; i<=rear; i++)
        cout << queue[i] << " ";
    }
    else{
        for (int i=front+1; i<=rear+capacity; i++)
        cout << queue[i%capacity] << " ";
    }
    cout << endl;
}

template <class T>
void CircularQueue<T>::ChangeSize1D(T* &arr, const int& size, const int& ToSize){
    T* tmp = new T[size];
    tmp = arr;
    arr = new T[ToSize];
    for(int i=0; i< size; ++i){
        arr[i] = tmp[i];
    }
    delete[] tmp;
    capacity = ToSize;
}


int main () {
    // Instantiating template class
    typedef CircularQueue<int> IntQueue;
    IntQueue q(5);

    // Push example
    q.Push(6);
    q.Push(5);
    q.Push(4);
    q.Push(3);
    q.Push(2);
    q.Push(1);
    q.Print();

    // get capacity
    cout << "Capacity: " << q.getCapcity() << endl;

    // Pop example
    q.Pop();
    q.Print();

    // front()/ rear()
    int front = q.Front();
    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    // Pop example
    q.Pop();
    q.Print();

    // front() rear()
    front = q.Front();
    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    // Push example
    q.Push(6);
    q.Push(5);
    q.Push(4);
    q.Push(3);
    q.Push(2);
    q.Push(1);
    q.Print();

    return 0;
}