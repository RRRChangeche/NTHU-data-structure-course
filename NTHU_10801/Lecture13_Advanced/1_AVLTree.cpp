// Ref: https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
// AVL Tree 
#include <iostream>
using namespace std;

template <class T> class AVLTree;

template <class T>
class TreeNode{
public: 
    TreeNode(T t, TreeNode<T>* left=NULL, TreeNode<T>* right=NULL){
        data = t;
        height = 1;
        leftChild = left;
        rightChild = right;
    }
    TreeNode(TreeNode<T>* node){ 
        data = node->data;
        height = node->height;
        leftChild = node->leftChild;
        rightChild = node->rightChild;
    }

    void updateHeight();
    int getHeight(TreeNode<T>* node);
    int bf();   // balance factor

    T data;
    int height;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;
};

template <class T>
int TreeNode<T>::getHeight(TreeNode<T>* node){
    if (node) node->height;
    return 0;
}

template <class T>
void TreeNode<T>::updateHeight(){
    if (!this) return; 
    height = max(getHeight(this->leftChild), getHeight(this->rightChild)) + 1;
}

template <class T>
int TreeNode<T>::bf(){
    return getHeight(this->leftChild)-getHeight(this->rightChild);
}


template <class T>
class AVLTree{
public: 
    // constructor
    AVLTree(void) {root=NULL;}
    ~AVLTree(){}

    // Tree operations
    TreeNode<T>* Insert(TreeNode<T>* node);
    void Delete(const T& t);
    TreeNode<T>* leftRotate(TreeNode<T>* node);
    TreeNode<T>* rightRotate(TreeNode<T>* node);

private:
    TreeNode<T>* root;

    // private method
    TreeNode<T>* rebalance(TreeNode<T>* node);
};

template <class T> 
TreeNode<T>* AVLTree<T>::leftRotate(TreeNode<T>* node){
    TreeNode<T>* node_r = node->rightChild;
    TreeNode<T>* node_rl = node_r->leftChild;
    node->rightChild = node_rl;
    node_r->leftChild = node;
    node->updateHeight();
    node_r->updateHeight();
    return node_r;
}

template <class T> 
TreeNode<T>* AVLTree<T>::rightRotate(TreeNode<T>* node){
    TreeNode<T>* node_l = node->leftChild;
    TreeNode<T>* node_lr = node_l->rightChild;
    node->leftChild = node_lr;
    node_l->rightChild = node;
    node->updateHeight();
    node_l->updateHeight();
    return node_l;
}

template <class T>
TreeNode<T>* AVLTree<T>::rebalance(TreeNode<T>* node){
    // LL case
    if (node->bf()>1 && node->leftChild->bf()>=0){
        return rightRotate(node);
    }
    // RR case
    if (node->bf()<-1 && node->rightChild->bf()<=0){
        return leftRotate(node);
    }
    // RL case
    if (node->bf()>1 && node->leftChild->bf()<0){
        // do left rotation the right rotation
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }
    // LR case
    if (node->bf()<-1 && node->rightChild->bf()>0){
        // do right rotation then left rotation
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }
    return node;
}

template <class T>
TreeNode<T>* AVLTree<T>::Insert(TreeNode<T>* node){
    // BST insertion ...
    TreeNode<T>* p = root, *pp=0;
    // traversal BST and find if key exists
    // if not, store the search terminate node's parent as pp
    while(p){
        pp = p;
        if (node->data < p->data) p = p->leftChild;
        else if (node->data > p->data) p = p->rightChild;
        else {return node;} // found same key, update the value of element
    }

    // perform the insertion
    // set p as pp's leftChild or rightChild
    p = new TreeNode(node);
    if (root)   // if tree is not empty
    {
        if (node->data < pp->data) pp->leftChild = p;
        else pp->rightChild = p;
    }
    else root=p;

    // rebalance from node to root
    node->updateHeight();
    return rebalance(node);
}

template <class T>
void AVLTree<T>::Delete(const T& data){
    // find node to be delete, and pNode is it's parent node
    TreeNode<T>* node=root, *pNode = 0;
    while(node){
        if (data == node->data) break;  // found node with key
        pNode = node;
        if (data < node->data) node = node->leftChild;
        else if (data > node->data) node = node->rightChild;  
    }

    if (node){
        cout << "delete node with key=" << node->data  << " in BST"<< endl;
        // node is root
        // node with two children (non-leaf node)
        if (node->leftChild && node->rightChild || node == root){       
            // delete node and replace by smallest node in right subtree
            TreeNode<T>* rNode = root->rightChild;
            TreeNode<T>* rminNode = node->rightChild;
            while(rminNode->leftChild) rminNode = rminNode->leftChild;
            Delete(rminNode->data);

            // if node is root
            if(node == root) {
                root->data = rminNode->data;
            }
            else{
                node->data = rminNode->data;
            }
            // root->data = rminNode->data;
            // root->rightChild = rNode;
            return;
        }
        else{
        // node with no child (leaf node)
            if (!node->leftChild && !node->rightChild){ 
                if (data < pNode->data) pNode->leftChild = NULL;
                else pNode->rightChild = NULL;
            }
        // node with one child (non-leaf node)
            else{         
                // if node has leftChild                              
                if (node->leftChild){                   
                    if (data < pNode->data) pNode->leftChild = node->leftChild;     // subtree is at pNode's leftside
                    else pNode->rightChild = node->leftChild;                       // subtree is at pNode's rightside
                }
                // if node has rightChild
                else if (node->rightChild){             
                    if (data < pNode->data) pNode->leftChild = node->rightChild;    // subtree is at pNode's leftside
                    else pNode->rightChild = node->rightChild;                      // subtree is at pNode's rightside
                }
            }
            delete node;
            node = NULL;
        }
    }
    else {                                              // key not found 
        cout << "key=" << data << " not found in BST" << endl; 
    }   

    // rebalance from node to root
    pNode->updateHeight();
    rebalance(pNode);
} 


int main(){
    AVLTree<int> tree;

    TreeNode<int>* nodeA = new TreeNode<int>(1);
    TreeNode<int>* nodeB = new TreeNode<int>(5);
    TreeNode<int>* nodeC = new TreeNode<int>(2);
    TreeNode<int>* nodeD = new TreeNode<int>(3);
    TreeNode<int>* nodeE = new TreeNode<int>(4);
    
    tree.Insert(nodeA);
    tree.Insert(nodeB);
    tree.Insert(nodeC);
    tree.Insert(nodeD);
    tree.Insert(nodeE);
    tree.Delete(1);
    tree.Delete(2);

    return 0;
}