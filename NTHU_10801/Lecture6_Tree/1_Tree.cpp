// Ref: http://alrightchiu.github.io/SecondRound/binary-tree-traversalxun-fang.html
#include <iostream>
#include <string>
using namespace std;

template <class T> class Tree; // forward declaration

template <class T>
class TreeNode{
friend class Tree<T>;
public: 
    // constructor
    TreeNode<T>(T value, TreeNode<T>* left=NULL, TreeNode<T>* right=NULL){
        data = value;
        leftChild = left;
        rightChild = right;
    }
    T data;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;
};

template <class T>
class Tree{
public:
    // constructor
    Tree(void) {root=NULL;}
    Tree(TreeNode<T>* node) {root=node;}

    void Visit(TreeNode<T>*);
    void InOrder();
    void InOrder(TreeNode<T>*);
    void PreOrder();
    void PreOrder(TreeNode<T>*);
    void PostOrder();
    void PostOrder(TreeNode<T>*);
    // void InsertBack(const T&);
    // void InsertFront(const T&);
    // void Delete(TreeNode<T>*, TreeNode<T>*);
    // void Delete(const T&);
    // void Concatenate(Tree<T>&);
    // void Reverse();
    // void Clear();
    // void Print();

private:
    TreeNode<T>* root;
};


template <class T> 
void Tree<T>::Visit(TreeNode<T>* node){
    cout << node->data << " ";
}

template <class T>
void Tree<T>::PreOrder(){
    cout << "PreOrder: ";
    PreOrder(root);
    cout << endl;
}

template <class T>
void Tree<T>::PreOrder(TreeNode<T>* node){
    // recursive inorder traversal function
    if (node){
        Visit(node);    // printout information
        PreOrder(node->leftChild);
        PreOrder(node->rightChild);
    }
}

template <class T>
void Tree<T>::InOrder(){
    cout << "InOrder: ";
    InOrder(root);
    cout << endl;
}

template <class T>
void Tree<T>::InOrder(TreeNode<T>* node){
    // recursive inorder traversal function
    if (node){
        InOrder(node->leftChild);
        Visit(node);    // printout information
        InOrder(node->rightChild);
    }
}

template <class T>
void Tree<T>::PostOrder(){
    cout << "PostOrder: ";
    PostOrder(root);
    cout << endl;
}

template <class T>
void Tree<T>::PostOrder(TreeNode<T>* node){
    // recursive inorder traversal function
    if (node){
        PostOrder(node->leftChild);
        PostOrder(node->rightChild);
        Visit(node);    // printout information
    }
}

// template <class T>
// void Tree<T>::InsertBack(const T& e){
//     if(first)   // non-empty chain
//     {
//         last->link = new TreeNode<T>(e);
//         last = last->link;
//         last->link = first;
//     }
//     else    // Insert into an empty chain
//     {
//         first = last = new TreeNode<T>(e);
//         first->link = last;
//         last->link = first;
//     }
// }

// template <class T>
// void Tree<T>::InsertFront(const T& e){
//     TreeNode<T>* newNode = new TreeNode<T>(e);
//     if(first)   // non-empty chain
//     {
//         newNode->link = first; // 接到頭
//         // newNode->link = last->link; // 接到頭
//         first = newNode;
//         last->link = first;
//     }
//     else    // Insert into an empty chain
//     {
//         first = last = newNode;
//         first->link = last;
//         last->link = first;
//     }
// }

// template <class T>
// void Tree<T>::Delete(TreeNode<T>* target, TreeNode<T>* preNode){
//     // target is node to be deleted, preNode is the node preceding target
//     if(!target || !preNode) cout << "Cannot delete NULL nodes!" << endl;
//     if (target == first) first = first->link;
//     else preNode->link = target->link;
//     delete target; target = NULL;
// }

// template <class T>
// void Tree<T>::Delete(const T& x){
//     TreeNode<T>* current = first;
//     TreeNode<T>* preNode = 0;
//     // link list為空的情況
//     if (first == 0) {
//         cout << "Link list is empty!" << endl;
//         return;
//     }

//     // 找到x存在第一筆的情況
//     if (first->data == x){
//         cout << "found " << x << " at first and delete it!" << endl;
//         first = first->link;
//         delete current;
//         current = 0;
//         last->link = first;
//         return;
//     }
//     else{
//         // 遍歷整個link list
//         while (current->link != first && current->data != x){
//             preNode = current;
//             current = current->link;
//         }

//         // list中不存在x
//         if (current == 0){
//             cout << "Cannot found " << x << " in list!" << endl;
//             return;
//         }
//         // list中存在x, 且在最尾部
//         else if (current->link == first)
//         {
//             cout << "found " << x << " in list and delete it!" << endl;
//             preNode->link = current->link;
//             delete current;
//             current = 0;
//             last = preNode;
//             last->link = first;
//         }
//         // list中存在x, 且在中間
//         else{
//             cout << "found " << x << " in list and delete it!" << endl;
//             preNode->link = current->link;
//             delete current;
//             current = 0;
//         }
//     }
// }

// template <class T>
// void Tree<T>::Concatenate(Tree<T>& x){
//     // b is concatenated to the end of *this
//     // if non-empty chain
//     // 將chain的last node中的link指向x node的first node, 再將chain的last node 
//     if(first) {last->link=x.first; last=x.last;}     
//     // 如果chain是空的, 則chain=傳進來的chain
//     else {last = x.last; first = x.first;}
//     x.first = x.last = 0;
// }

// template <class T>
// void Tree<T>::Reverse(){
//     TreeNode<T>* previous = NULL;
//     TreeNode<T>* current = first;
//     TreeNode<T>* next = first->link;
//     while(next != first){
//         current->link = previous;
//         previous = current;
//         current = next;
//         next = next->link;
//     }
//     current->link = previous;   // current->link最後指向previous
//     first->link = current;      // 將first->link指向尾部current
//     last = first;               // 將尾部last node設為first
//     first = current;            // 將頭部first node設為current
//     cout << "Reverse the link list!" << endl;
// }

// template <class T>
// void Tree<T>::Clear(){
//     while(first != 0){
//         TreeNode<T>* current = first;
//         first = first->link;
//         delete current;
//         current = 0;
//     }
// }

// template <class T>
// void Tree<T>::Print(){
//     if (first == 0) {
//         cout << "Link list is empty!" << endl;
//         return;
//     }

//     TreeNode<T>* current = first;
//     do{
//         cout << current->data << " ";
//         current = current->link;
//     } while(current != first);
//     cout << endl;
// }


int main () {
    // TreeNode instantiation
    typedef TreeNode<const char*> TNodeString;
    TNodeString* nodeA = new TreeNode("A"); TNodeString* nodeB = new TreeNode("B"); 
    TNodeString* nodeC = new TreeNode("C"); TNodeString* nodeD = new TreeNode("D"); 
    TNodeString* nodeE = new TreeNode("E"); TNodeString* nodeF = new TreeNode("F"); 
    TNodeString* nodeG = new TreeNode("G"); TNodeString* nodeH = new TreeNode("H"); 
    TNodeString* nodeI = new TreeNode("I");

    // construct the Binary Tree
    nodeA->leftChild = nodeB; nodeA->rightChild = nodeC; 
    nodeB->leftChild = nodeD; nodeB->rightChild = nodeE; 
    nodeE->leftChild = nodeG; nodeE->rightChild = nodeH; 
    nodeC->leftChild = nodeF; nodeF->rightChild = nodeI;

    Tree T(nodeA);

    T.PreOrder();
    T.InOrder();
    T.PostOrder();
    // T.PreOrder(T.root);
    // std::cout << std::endl;
    // T.InOrder(T.root);
    // std::cout << std::endl;
    // T.PostOrder(T.root);
    // std::cout << std::endl;
    // T.LevelOrder();
    // std::cout << std::endl;    
    return 0;
}