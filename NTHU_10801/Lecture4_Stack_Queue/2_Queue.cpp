// Ref: http://users.cis.fiu.edu/~weiss/Deltoid/vcstl/templatess
#include <iostream>
using namespace std;

// define ChangeSize1D function template
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
class Queue{
public:
    // Constructor
    Queue(int capacity = 10);
    ~Queue();

    bool isEmpty() const;   // check if queue is empty
    T& Front() const;    // return the top element 
    T& Rear() const;    // return the top element 
    void Push(const T& item);   // Insert a new element at top
    void Pop(); // delete one element from top
    void Print();

private:
    T* queue;
    int front, rear;    // init -1
    int capacity;
    int count;
};

// constructor
template <class T>
Queue<T>::Queue(int c){
    capacity = c;
    queue = new T[capacity];
    // front = 0;
    // rear = -1;
    front = rear = -1;
    // front = rear = 0;
    count = 0;
}

template <class T>
Queue<T>::~Queue(){
    delete [] queue;
}

// member function
template <class T>
// bool Queue<T>::isEmpty() const { return front==rear; }
bool Queue<T>::isEmpty() const { return count; }

template <class T>
T& Queue<T>::Front() const {
    // if (isEmpty()) throw "Queue is empty!";
    // return queue[(front+1)%capacity];
    return queue[front];
}

template <class T>
T& Queue<T>::Rear() const {
    // if (isEmpty()) throw "Queue is empty!";
    // return queue[rear];
    return queue[front+count];
}

template <class T>
void Queue<T>::Push(const T& item){ // add item at rear of queue
    // if((rear+1) % capacity == 0 || (rear+1) % capacity == front)    // queue is going to full, double the capacity
    if((front+count)+1 % capacity == rear)    // queue is going to full, double the capacity
    {
        ChangeSize1D(queue, capacity, 2*capacity);
    }
    rear = (rear+1) % capacity;
    // queue[rear] = item;
    queue[front+count+1] = item;
    cout << "Push " << queue[front+count+1] << " into the queue" << endl;
    count++;
}

template <class T>
void Queue<T>::Pop(){ // delete front element from queue
    // if (isEmpty()) throw "Queue is empty!, cannot delete";
    front = (front+1) % capacity;
    queue[front].~T();
    cout << "Pop " << queue[front] << " from the queue" << endl;
    count--;
}

template <class T>
void Queue<T>::Print(){
    // cout << "Front: " << front << endl;
    // cout << "Rear: " << rear << endl;
    // cout << "Count: " << count << endl;
    cout << "queue: ";
    for (int i=front+1; i<front+1+count; i++)
        cout << queue[i] << " ";
    cout << endl;
}


int main () {
    // Instantiating template class
    typedef Queue<int> IntQueue;
    IntQueue q(5);
    q.Print();

    // Push example
    q.Push(6);
    q.Push(5);
    q.Push(4);
    q.Push(3);
    q.Push(2);
    q.Push(1);
    q.Print();

    // Pop example
    q.Pop();
    q.Print();

    // front()
    int front = q.Front();
    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    return 0;
}