// Ref:
#include <iostream>
#include <string>
using namespace std;

// forward declaration of Binary Search Tree
template <class T, class K, class E> class BSTree;
// template <class T> class BSTree; 


// declare key-value pair
template <class K, class E>
class Pair{
public: 
    Pair() {}
    Pair(K k, E elem) {
        key = k;
        element = elem;
    }

private:
    K key;
    E element;
};

// declare TreeNode
template <class T>
class TreeNode{
// friend class BSTree<T, K, E>;
public: 
    // constructor
    TreeNode<T>(T value, TreeNode<T>* left=NULL, TreeNode<T>* right=NULL){
        data = value;
        leftChild = left;
        rightChild = right;
    }

private:
    T data;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;
    int leftSize;
};

// declare Binary Search Tree
template <class T, class K, class E>
class BSTree{
public:
    BSTree() {root=NULL;}
    BSTree(TreeNode<T>* node) {root=node;}
    ~BSTree() {}

    T* Get(const K& k);
    T* GetByRecursive(const K& k);
private:
    T* GetByRecursive(TreeNode<T>* node, const K& k);
public:
    T* GetByRank(int r);
    void Insert(TreeNode<T>* node);

private:
    TreeNode<T>* root;
};


// Interative search
template <class T, class K, class E>
T* BSTree<T, K, E>::Get(const K& key){
    TreeNode<T>* currentNode = root;
    while(currentNode){
        if (key < currentNode->data.key) currentNode = currentNode->leftChild;
        else if (key > currentNode->data.key) currentNode = currentNode->rightChild;
        else return & currentNode->data;
    }

    return NULL;     // no match found
}

// Recursive search
template <class T, class K, class E>
T* BSTree<T, K, E>::GetByRecursive(const K& key){
    return GetByRecursive(root, key);
}

template <class T, class K, class E>
T* GetByRecursive(TreeNode<T>* node, const K& k){
    if (!node) {
        cout << "Node not found!" << endl;
        return 0;
    } 
    if (k < node->data) GetByRecursive(node->leftChild, k);
    if (k > node->data) GetByRecursive(node->rightChild, k);
    return &node->data;
}

// Search by rank
template <class T, class K, class E>
T* BSTree<T, K, E>::GetByRank(int r){
    // Search BST for the rth smallest pair
    TreeNode<T>* currentNode = root;
    while(currentNode){
        if(r < currentNode->leftSize) 
            currentNode = currentNode->leftChild;
        else if(r > currentNode->leftSize) { 
            r -= currentNode->leftSize;
            currentNode = currentNode->rigthChild;
        }
        else return &currentNode->data;
    }
    return 0;
}

template <class T, class K, class E>
void BSTree<T, K, E>::Insert(TreeNode<T>* node){
    TreeNode<T>* p = root, *pp=0;
    while(p){
        pp = p;
        if (node->data.key < p->data.key) p = p->leftChild;
        else if (node->data.key > p->data.key) p = p->rightChild;
        else {p.data.element = node->data.element; return;} // found same key, update the value of element
    }
    // perform the insertion
    p = new Pair<K,E>(node->data);
    if (root)   // if tree is not empty
    {
        if (node->data.key < pp->data.key) pp->leftChild = p;
        else pp->rightChild = p;
    }
    else root=p;
}


int main () {
    // TreeNode instantiation
    typedef TreeNode<Pair<int, const char*>> TNodePair;
    Pair<int, const char*> pairA(9, "A");
    Pair<int, const char*> pairB(8, "B");
    TNodePair* nodeA = new TreeNode(pairA); TNodePair* nodeB = new TreeNode(pairB);
    // TNodePair* nodeC = new TreeNode(new Pair(7, "C")); TNodePair* nodeD = new TreeNode(new Pair(6, "D")); 
    // TNodePair* nodeE = new TreeNode(new Pair(5, "E")); TNodePair* nodeF = new TreeNode(new Pair(4, "F")); 
    // TNodePair* nodeG = new TreeNode(new Pair(3, "G")); TNodePair* nodeH = new TreeNode(new Pair(2, "H")); 
    // TNodePair* nodeI = new TreeNode(new Pair(1, "I"));

    BSTree<Pair<int, const char*>,int,const char*> T;
    T.Insert(nodeA);
    return 0;
}