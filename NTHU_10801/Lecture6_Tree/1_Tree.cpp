// Ref: http://alrightchiu.github.io/SecondRound/binary-tree-traversalxun-fang.html
#include <iostream>
#include <stack>
#include <queue>
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
    void PreOrder();
    void PreOrder(TreeNode<T>*);
    void InOrder();
    void InOrder(TreeNode<T>*);
    void PostOrder();
    void PostOrder(TreeNode<T>*);
    void NonRecPreOrder(TreeNode<T>*);
    void NonRecInOrder(TreeNode<T>*);
    void NonRecPostOrder(TreeNode<T>*);
    void LevelOrder();
    // void isEmpty();
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

// public: 
//     class 
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

template <class T>
void Tree<T>::NonRecPreOrder(TreeNode<T>* node){
    cout << "Non-recursive PreOrder: ";
    stack<TreeNode<T>*> s;
    TreeNode<T>* currentNode = node;

    while(1){
        while(currentNode){
            Visit(currentNode);
            s.push(currentNode->rightChild);
            currentNode = currentNode->leftChild;
        }

        if (s.empty()) { cout << endl; return;}    // all nodes are visited
        currentNode = s.top();
        s.pop();
    }
    cout << endl;
}

template <class T>
void Tree<T>::NonRecInOrder(TreeNode<T>* node){
    cout << "Non-recursive InOrder: ";
    stack<TreeNode<T>*> s;
    TreeNode<T>* currentNode = node;

    while(1){
        // 先找到最左邊的node, 沿途存入stack
        while(currentNode){
            s.push(currentNode);
            currentNode = currentNode->leftChild;
        }

        // 如果stack為空則結束
        if (s.empty()) { cout << endl; return;}    // all nodes are visited
        currentNode = s.top();  // 取出stack最上面的node處理
        s.pop();
        Visit(currentNode);
        currentNode = currentNode->rightChild;   // 將currentNode設為rightChild
    }
}

// Ref: https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
template <class T>
void Tree<T>::NonRecPostOrder(TreeNode<T>* node){
    cout << "Non-recursive PostOrder: ";
    stack<TreeNode<T>*> s;
    TreeNode<T>* currentNode = node;

    while(1){
        while(currentNode){
            if (currentNode->rightChild) s.push(currentNode->rightChild);
            s.push(currentNode);
            currentNode = currentNode->leftChild;
        }

        currentNode = s.top();
        s.pop();
        if (s.empty()){
            Visit(currentNode);
            cout << endl;
            return;
        }
        if (currentNode->rightChild && currentNode->rightChild == s.top()) 
        {
            s.pop();
            s.push(currentNode);
            currentNode = currentNode->rightChild;
        }
        else{
            Visit(currentNode);
            currentNode = NULL;
        }
    }
}

template <class T>
void Tree<T>::LevelOrder(){
    cout << "LevelOrder: ";
    queue<TreeNode<T>*> q;
    TreeNode<T>* currentNode = root;
    while(currentNode){
        // print currnet node
        Visit(currentNode);
        // push left/right into queue
        if (currentNode->leftChild) q.push(currentNode->leftChild);
        if (currentNode->rightChild) q.push(currentNode->rightChild);
        // leave while loop when q is empty
        if (q.empty()) return;
        // pop front node in the queue and set as current node
        currentNode = q.front();
        q.pop();
    }
    cout << endl;
}


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
    T.NonRecPreOrder(nodeA);
    T.NonRecInOrder(nodeA);
    T.NonRecPostOrder(nodeA);
    T.LevelOrder();   
    return 0;
}