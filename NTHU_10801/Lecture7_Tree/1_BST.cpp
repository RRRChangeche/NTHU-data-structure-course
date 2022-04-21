// Ref:
#include <iostream>
#include <string>
using namespace std;

// forward declaration of Binary Search Tree
template <class K, class E> class BSTree;

// declare TreeNode
template <class K, class E>
class TreeNode{
friend class BSTree<K, E>;
public: 
    // constructor
    TreeNode(K k, E elem, TreeNode<K, E>* left=NULL, TreeNode<K, E>* right=NULL){
        key = k;
        element = elem;
        leftChild = left;
        rightChild = right;
        leftSize = GetLeftSize(this);
    }
    TreeNode(TreeNode<K,E>* node){ 
        key = node->key;
        element = node->element;
        leftChild = node->leftChild;
        rightChild = node->rightChild;
        leftSize = GetLeftSize(node);
    }
    // ~TreeNode() { delete this; }

    int GetLeftSize(TreeNode<K,E>* node){
        int count = 0;
        while (node){
            node = node->leftChild;
            count++;
        }
        return count;
    };

    int GetLeftSize(){
        int count = 0;
        TreeNode<K,E>* node = this;
        while (node){
            node = node->leftChild;
            count++;
        }
        return count;
    };
 
    E GetElement(){ 
        if (!this) throw "node is NULL\n";
        return element;
    }

private:
    K key;
    E element;
    TreeNode<K, E>* leftChild;
    TreeNode<K, E>* rightChild;
    int leftSize;
};

// declare Binary Search Tree
template <class K, class E>
class BSTree{
public:
    BSTree() {root=NULL;}
    BSTree(TreeNode<K,E>* node) {root=node;}
    ~BSTree() {}

    TreeNode<K,E>* Get(const K& k);
    TreeNode<K,E>* GetByRecursive(const K& k);
private:
    TreeNode<K,E>* GetByRecursive(TreeNode<K,E>* node, const K& k);
public:
    TreeNode<K,E>* GetByRank(int r);
    void Insert(TreeNode<K,E>* node);
    void Delete(const K& k);

private:
    TreeNode<K,E>* root;
};


// Interative search
template <class K, class E>
TreeNode<K,E>* BSTree<K,E>::Get(const K& key){
    TreeNode<K,E>* currentNode = root;
    while(currentNode){
        if (key < currentNode->key) currentNode = currentNode->leftChild;
        else if (key > currentNode->key) currentNode = currentNode->rightChild;
        else return currentNode;
    }

    return NULL;     // no match found
}

// Recursive search
template <class K, class E>
TreeNode<K,E>* BSTree<K,E>::GetByRecursive(const K& key){
    return GetByRecursive(root, key);
}

template <class K, class E>
TreeNode<K,E>* BSTree<K,E>::GetByRecursive(TreeNode<K,E>* node, const K& k){
    if (!node) {
        cout << "Node not found!" << endl;
        return 0;
    } 
    if (k < node->key) GetByRecursive(node->leftChild, k);
    if (k > node->key) GetByRecursive(node->rightChild, k);
    return node;
}

// Search by rank
template <class K, class E>
TreeNode<K,E>* BSTree<K,E>::GetByRank(int r){
    // Search BST for the rth smallest pair
    TreeNode<K,E>* currentNode = root;
    while(currentNode){
        if(r < currentNode->GetLeftSize()) 
            currentNode = currentNode->leftChild;
        else if(r > currentNode->GetLeftSize()) { 
            r -= currentNode->GetLeftSize();
            currentNode = currentNode->rightChild;
        }
        else return currentNode;
    }
    return 0;
}

template <class K, class E>
// template <class T>
void BSTree<K,E>::Insert(TreeNode<K,E>* node){
    TreeNode<K,E>* p = root, *pp=0;
    // traversal BST and find if key exists
    // if not, store the search terminate node's parent as pp
    while(p){
        pp = p;
        if (node->key < p->key) p = p->leftChild;
        else if (node->key > p->key) p = p->rightChild;
        else {p->element = node->element; return;} // found same key, update the value of element
    }

    // perform the insertion
    // set p as pp's leftChild or rightChild
    p = new TreeNode(node);
    if (root)   // if tree is not empty
    {
        if (node->key < pp->key) pp->leftChild = p;
        else pp->rightChild = p;
    }
    else root=p;
}

template<class K, class E>
void BSTree<K,E>::Delete(const K& k){
    // find node to be delete, and pNode is it's parent node
    TreeNode<K,E> *node=root, *pNode = 0;
    while(node){
        if (k == node->key) break;  // found node with key
        pNode = node;
        if (k < node->key) node = node->leftChild;
        else if (k > node->key) node = node->rightChild;  
    }

    if (node){
        cout << "delete node with key=" <<node->key  << " in BST"<< endl;
        // node is root
        if (node == root) {
            // delete node and replace by smallest node in right subtree
            TreeNode<K,E>* lNode = node->leftChild;
            TreeNode<K,E>* rNode = node->rightChild;
            TreeNode<K,E>* sNode = node->rightChild;
            if (!sNode) {root = node->leftChild; return;}   // no right child
            while(sNode->leftChild){
                sNode = sNode->leftChild;
            } 
            delete node;
            node = NULL;
            root = sNode;
            root->leftChild = lNode;
            root->rightChild = rNode;
            return;
        }
        // node with two children (non-leaf node)
        if (node->leftChild && node->rightChild){       
            // delete node and replace by smallest node in right subtree
            TreeNode<K,E>* sNode = node->rightChild;
            while(sNode->leftChild) sNode = sNode->leftChild;
            delete node;
            node = sNode;
            delete sNode;
            sNode = NULL;
        }
        else{
        // node with no child (leaf node)
            if (!node->leftChild && !node->rightChild){ 
                if (k < pNode->key) pNode->leftChild = NULL;
                else pNode->rightChild = NULL;
            }
        // node with one child (non-leaf node)
            else{         
                // if node has leftChild                              
                if (node->leftChild){                   
                    if (k < pNode->key) pNode->leftChild = node->leftChild;     // subtree is at pNode's leftside
                    else pNode->rightChild = node->leftChild;                   // subtree is at pNode's rightside
                }
                // if node has rightChild
                else if (node->rightChild){             
                    if (k < pNode->key) pNode->leftChild = node->rightChild;    // subtree is at pNode's leftside
                    else pNode->rightChild = node->rightChild;                  // subtree is at pNode's rightside
                }
            }
            delete node;
            node = NULL;
        }
    }
    else {                                              // key not found 
        cout << "key=" << k << " not found in BST" << endl; 
    }   
}


int main () {
    // TreeNode instantiation
    typedef TreeNode<int, const char*> BSTNode;
    BSTNode* nodeA = new BSTNode(9, "A"); BSTNode* nodeB = new BSTNode(15, "B");
    BSTNode* nodeC = new BSTNode(7, "C"); BSTNode* nodeD = new BSTNode(6, "D"); 
    BSTNode* nodeE = new BSTNode(5, "E"); BSTNode* nodeF = new BSTNode(4, "F"); 
    BSTNode* nodeG = new BSTNode(3, "G"); BSTNode* nodeH = new BSTNode(2, "H"); 
    BSTNode* nodeI = new BSTNode(1, "I");

    BSTree<int,const char*> T;
    T.Insert(nodeA);
    T.Insert(nodeB);
    T.Insert(nodeC);
    T.Insert(nodeD);
    T.Insert(nodeE);
    T.Insert(nodeF);
    T.Insert(nodeG);
    T.Insert(nodeH);
    T.Insert(nodeI);
    cout << T.Get(9)->GetElement() << endl;
    cout << T.Get(15)->GetElement() << endl;
    cout << T.GetByRank(2)->GetElement() << endl;

    // Delete
    try{
        T.Delete(9);
        T.Delete(2);
        cout << T.GetByRank(2)->GetElement() << endl;
        T.Delete(7);
        cout << T.GetByRank(7)->GetElement() << endl;       // This line can work
        cout << T.GetByRank(9)->GetElement() << endl;       // This line cannot work, error!
    }
    catch (const char* msg){
        cerr << msg << endl;
    } 
    
    return 0;
}