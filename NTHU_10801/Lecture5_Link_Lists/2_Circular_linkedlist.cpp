// Ref:
#include <iostream>
using namespace std;

template <class T> class CircularChain; // forward declaration

template <class T>
class ChainNode{
friend class CircularChain<T>;
public: 
    // constructor
    ChainNode<T>(T value, ChainNode<T>* next=NULL){
        data = value;
        link = next;
    }
    T data;
    ChainNode<T>* link;
};

template <class T>
class CircularChain{
public:
    // constructor
    CircularChain(void) {first=last=NULL;}

    void Create2();
    void InsertBack(const T&);
    void InsertFront(const T&);
    void Delete(ChainNode<T>*, ChainNode<T>*);
    void Delete(const T&);
    void Concatenate(CircularChain<T>&);
    void Reverse();
    void Clear();
    void Print();

private:
    ChainNode<T>* first;
    ChainNode<T>* last;
};

template <class T>
void CircularChain<T>::Create2(){
    ChainNode<T>* second = new ChainNode(20, 0);   // next=0=NULL
    first = new ChainNode(10, second);
    last->link = first;
}

template <class T>
void CircularChain<T>::InsertBack(const T& e){
    if(first)   // non-empty chain
    {
        last->link = new ChainNode<T>(e);
        last = last->link;
        last->link = first;
    }
    else    // Insert into an empty chain
    {
        first = last = new ChainNode<T>(e);
        first->link = last;
        last->link = first;
    }
}

template <class T>
void CircularChain<T>::InsertFront(const T& e){
    ChainNode<T>* newNode = new ChainNode<T>(e);
    if(first)   // non-empty chain
    {
        newNode->link = first; // 接到頭
        // newNode->link = last->link; // 接到頭
        first = newNode;
        last->link = first;
    }
    else    // Insert into an empty chain
    {
        first = last = newNode;
        first->link = last;
        last->link = first;
    }
}

template <class T>
void CircularChain<T>::Delete(ChainNode<T>* target, ChainNode<T>* preNode){
    // target is node to be deleted, preNode is the node preceding target
    if(!target || !preNode) cout << "Cannot delete NULL nodes!" << endl;
    if (target == first) first = first->link;
    else preNode->link = target->link;
    delete target; target = NULL;
}

template <class T>
void CircularChain<T>::Delete(const T& x){
    ChainNode<T>* current = first;
    ChainNode<T>* preNode = 0;
    // link list為空的情況
    if (first == 0) {
        cout << "Link list is empty!" << endl;
        return;
    }

    // 找到x存在第一筆的情況
    if (first->data == x){
        cout << "found " << x << " at first and delete it!" << endl;
        first = first->link;
        delete current;
        current = 0;
        last->link = first;
        return;
    }
    else{
        // 遍歷整個link list
        while (current->link != first && current->data != x){
            preNode = current;
            current = current->link;
        }

        // list中不存在x
        if (current == 0){
            cout << "Cannot found " << x << " in list!" << endl;
            return;
        }
        // list中存在x, 且在最尾部
        else if (current->link == first)
        {
            cout << "found " << x << " in list and delete it!" << endl;
            preNode->link = current->link;
            delete current;
            current = 0;
            last = preNode;
            last->link = first;
        }
        // list中存在x, 且在中間
        else{
            cout << "found " << x << " in list and delete it!" << endl;
            preNode->link = current->link;
            delete current;
            current = 0;
        }
    }
}

template <class T>
void CircularChain<T>::Concatenate(CircularChain<T>& x){
    // b is concatenated to the end of *this
    // if non-empty chain
    // 將chain的last node中的link指向x node的first node, 再將chain的last node 
    if(first) {last->link=x.first; last=x.last;}     
    // 如果chain是空的, 則chain=傳進來的chain
    else {last = x.last; first = x.first;}
    x.first = x.last = 0;
}

template <class T>
void CircularChain<T>::Reverse(){
    ChainNode<T>* previous = NULL;
    ChainNode<T>* current = first;
    ChainNode<T>* next = first->link;
    while(next != first){
        current->link = previous;
        previous = current;
        current = next;
        next = next->link;
    }
    current->link = previous;   // current->link最後指向previous
    first->link = current;      // 將first->link指向尾部current
    last = first;               // 將尾部last node設為first
    first = current;            // 將頭部first node設為current
    cout << "Reverse the link list!" << endl;
}

template <class T>
void CircularChain<T>::Clear(){
    while(first != 0){
        ChainNode<T>* current = first;
        first = first->link;
        delete current;
        current = 0;
    }
}

template <class T>
void CircularChain<T>::Print(){
    if (first == 0) {
        cout << "Link list is empty!" << endl;
        return;
    }

    ChainNode<T>* current = first;
    do{
        cout << current->data << " ";
        current = current->link;
    } while(current != first);
    cout << endl;
}


int main () {
    typedef CircularChain<int> CLinkInt;
    CLinkInt clist;           // 建立LinkedList的object
    clist.Print();           // 目前list是空的
    clist.InsertBack(5);     // list: 5
    clist.InsertBack(3);     // list: 5 3
    clist.InsertFront(9);    // clist: 9 5 3
    clist.Print();           // 印出:  9 5 3
    clist.InsertBack(4);     // clist: 9 5 3 4
    clist.Print();           // 印出:  9 5 3 4
    clist.Delete(4);         // list是空的, 沒有4
    clist.Delete(9);         // clist: 5 3
    clist.Print();           // 印出:  5 3
    clist.InsertFront(8);    // clist: 8 5 3
    clist.Print();           // 印出:  8 5 3
    clist.Reverse();         // clist: 3 5 8
    clist.Print();           // 印出:  3 5 8
    clist.Clear();        // 清空list
    clist.Print();        // 印出: List is empty
    return 0;
}