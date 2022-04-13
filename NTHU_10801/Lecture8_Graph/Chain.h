#ifndef MY_CHAIN_HEADER
#define MY_CHAIN_HEADER
#include <iostream>
using namespace std;

template <class T> class Chain; // forward declaration

template <class T>
class ChainNode{
friend class Chain<T>;
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
class Chain{
public:
    // constructor
    Chain(void) {first=last=NULL;} //cout << "Enter Chain<T> constructor" << endl;}

    void Create2();
    void InsertBack(const T&);
    void InsertFront(const T&);
    void Delete(ChainNode<T>*, ChainNode<T>*);
    void Delete(const T&);
    void Concatenate(Chain<T>&);
    void Reverse();
    void Clear();
    int Size();
    ChainNode<T>* GetFirstNode();
    void Print();

private:
    ChainNode<T>* first;
    ChainNode<T>* last;
};
#endif

