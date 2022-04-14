#include "Chain.h"
#include <iostream>
using namespace std;

template <class T>
void Chain<T>::Create2(){
    ChainNode<T>* second = new ChainNode(20, 0);   // next=0=NULL
    first = new ChainNode(10, second);
}

template <class T>
void Chain<T>::InsertBack(const T& e){
    if(first)   // non-empty chain
    {
        last->link = new ChainNode<T>(e);
        last = last->link;
    }
    else    // Insert into an empty chain
        first = last = new ChainNode<T>(e);
}

template <class T>
void Chain<T>::InsertFront(const T& e){
    if(first)   // non-empty chain
    {
        ChainNode<T>* node = new ChainNode<T>(e);
        node->link = first;
        first = node;
    }
    else    // Insert into an empty chain
        first = last = new ChainNode<T>(e);
}

template <class T>
void Chain<T>::Delete(ChainNode<T>* target, ChainNode<T>* preNode){
    // target is node to be deleted, preNode is the node preceding target
    if(!target || !preNode) cout << "Cannot delete NULL nodes!" << endl;
    if (target == first) first = first->link;
    else preNode->link = target->link;
    delete target; target = NULL;
}

template <class T>
void Chain<T>::Delete(const T& x){
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
        return;
    }
    else{
        // 遍歷整個link list
        while (current != 0 && current->data != x){
            preNode = current;
            current = current->link;
        }

        // list中不存在x
        if (current == 0){
            cout << "Cannot found " << x << " in list!" << endl;
            return;
        }
        // list中存在x
        else{
            cout << "found " << x << " in list and delete it!" << endl;
            preNode->link = current->link;
            delete current;
            current = 0;
        }
    }

    
}

template <class T>
void Chain<T>::Concatenate(Chain<T>& x){
    // b is concatenated to the end of *this
    // if non-empty chain
    // 將chain的last node中的link指向x node的first node, 再將chain的last node 
    if(first) {last->link=x.first; last=x.last;}     
    // 如果chain是空的, 則chain=傳進來的chain
    else {last = x.last; first = x.first;}
    x.first = x.last = 0;
}

template <class T>
void Chain<T>::Reverse(){
    ChainNode<T>* current = first;
    ChainNode<T>* previous = NULL;
    while(current){
        ChainNode<T>* r = previous;
        previous = current;
        current = current->link;
        previous->link = r;
    }
    first = previous;
}

template <class T>
void Chain<T>::Clear(){
    while(first != 0){
        ChainNode<T>* current = first;
        first = first->link;
        delete current;
        current = 0;
    }
}

template <class T>
int Chain<T>::Size(){
    int count = 0;
    ChainNode<T>* node = first;
    while (node){
        count++;
        node = node->link;
    }
    return count;
}

template <class T>
ChainNode<T>* Chain<T>::GetFirstNode(){
    return first;
}

template <class T>
void Chain<T>::Print(){
    if (first == 0) {
        cout << "Link list is empty!" << endl;
        return;
    }

    ChainNode<T>* current = first;
    while(current != 0){
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;
}


