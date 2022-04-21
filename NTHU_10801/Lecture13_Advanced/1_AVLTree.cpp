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
        // if (node == root) {
        // //     // delete node and replace by smallest node in right subtree
        // //     TreeNode<T>* lNode = node->leftChild;
        // //     TreeNode<T>* rNode = node->rightChild;
        // //     TreeNode<T>* sNode = node->rightChild;
        // //     if (!sNode) {root = node->leftChild; return;}   // no right child
        // //     while(sNode->leftChild){
        // //         pNode = sNode;
        // //         sNode = sNode->leftChild;
        // //     } 
        // //     delete node;
        // //     node = NULL;
        // //     pNode->leftChild = sNode->rightChild;
        // //     root = sNode;
        // //     root->leftChild = lNode;
        // //     root->rightChild = rNode;
        // //     return;
        // }
        // node with two children (non-leaf node)
        if (node->leftChild && node->rightChild || node == root){       
            // delete node and replace by smallest node in right subtree
            // TreeNode<T>* sNode = node->rightChild;
            // while(sNode->leftChild) sNode = sNode->leftChild;
            // delete node;
            // node = sNode;
            // // delete sNode;
            // // sNode = NULL;

            TreeNode<T>* rNode = root->rightChild;
            TreeNode<T>* rminNode = node->rightChild;
            while(rminNode->leftChild) rminNode = rminNode->leftChild;
            Delete(rminNode->data);
            root->data = rminNode->data;
            root->rightChild = rNode;
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


// #include <iostream>
// #include <queue>
// #include <unordered_map>
// using namespace std;

// struct node {
//     struct node *left;
//     int data;
//     int height;
//     struct node *right;

// };

// class AVL
// {
// private:
    
// public:
//     struct node * root;
//     AVL(){
//         this->root = NULL;

//     }

//     int calheight(struct node *p){

//             if(p->left && p->right){
//                 if (p->left->height < p->right->height)
//                     return p->right->height + 1;
//                 else return  p->left->height + 1;
//             }
//             else if(p->left && p->right == NULL){
//                return p->left->height + 1;
//             }
//             else if(p->left ==NULL && p->right){
//                return p->right->height + 1;
//             }
//             return 0;

//     }

//     int bf(struct node *n){
//             if(n->left && n->right){
//                 return n->left->height - n->right->height; 
//             }
//             else if(n->left && n->right == NULL){
//                 return n->left->height; 
//             }
//             else if(n->left== NULL && n->right ){
//                 return -n->right->height;
//             }
//     }

//     struct node * llrotation(struct node *n){
//         struct node *p;
//         struct node *tp;
//         p = n;
//         tp = p->left;

//         p->left = tp->right;
//         tp->right = p;

//         return tp; 
//     }


//     struct node * rrrotation(struct node *n){
//         struct node *p;
//         struct node *tp;
//         p = n;
//         tp = p->right;

//         p->right = tp->left;
//         tp->left = p;

//         return tp; 
//     }


//     struct node * rlrotation(struct node *n){
//         struct node *p;
//         struct node *tp;
//         struct node *tp2;
//         p = n;
//         tp = p->right;
//         tp2 =p->right->left;

//         p -> right = tp2->left;
//         tp ->left = tp2->right;
//         tp2 ->left = p;
//         tp2->right = tp; 
        
//         return tp2; 
//     }

//     struct node * lrrotation(struct node *n){
//         struct node *p;
//         struct node *tp;
//         struct node *tp2;
//         p = n;
//         tp = p->left;
//         tp2 =p->left->right;

//         p -> left = tp2->right;
//         tp ->right = tp2->left;
//         tp2 ->right = p;
//         tp2->left = tp; 
        
//         return tp2; 
//     }

//     struct node* insert(struct node *r,int data){
        
//         if(r==NULL){
//             struct node *n;
//             n = new struct node;
//             n->data = data;
//             r = n;
//             r->left = r->right = NULL;
//             r->height = 1; 
//             return r;             
//         }
//         else{
//             if(data < r->data)
//             r->left = insert(r->left,data);
//             else
//             r->right = insert(r->right,data);
//         }

//         r->height = calheight(r);

//         if(bf(r)==2 && bf(r->left)==1){
//             r = llrotation(r);
//         }
//         else if(bf(r)==-2 && bf(r->right)==-1){
//             r = rrrotation(r);
//         }
//         else if(bf(r)==-2 && bf(r->right)==1){
//             r = rlrotation(r);
//         }
//         else if(bf(r)==2 && bf(r->left)==-1){
//             r = lrrotation(r);
//         }        

//         return r;

//     }

//     void levelorder_newline(){
//         if (this->root == NULL){
//             cout<<"\n"<<"Empty tree"<<"\n";
//             return;            
//         }
//         levelorder_newline(this->root);
//     }

//     void levelorder_newline(struct node *v){
//         queue <struct node *> q;
//         struct node *cur;
//         q.push(v);
//         q.push(NULL);      

//         while(!q.empty()){
//             cur = q.front();
//             q.pop();
//             if(cur == NULL && q.size()!=0){
//                 cout<<"\n";
                
//                 q.push(NULL);
//                 continue;
//             }
//             if(cur!=NULL){
//                 cout<<" "<<cur->data;

//                 if (cur->left!=NULL){
//                 q.push(cur->left);
//                 }
//                 if (cur->right!=NULL){
//                     q.push(cur->right);
//                 }
//             }
//         }
//     }
 
//     struct node * deleteNode(struct node *p,int data){

//         if(p->left == NULL && p->right == NULL){
//                 if(p==this->root)
//                     this->root = NULL;
//             delete p;
//             return NULL;
//         }

//         struct node *t;
//         struct node *q;
//         if(p->data < data){
//             p->right = deleteNode(p->right,data);
//         }
//         else if(p->data > data){
//             p->left = deleteNode(p->left,data);
//         }
//         else{
//             if(p->left != NULL){
//                 q = inpre(p->left);
//                 p->data = q->data;
//                 p->left=deleteNode(p->left,q->data);
//             }
//             else{
//                 q = insuc(p->right);
//                 p->data = q->data;
//                 p->right = deleteNode(p->right,q->data);
//             }
//         }

//         if(bf(p)==2 && bf(p->left)==1){ p = llrotation(p); }                  
//         else if(bf(p)==2 && bf(p->left)==-1){ p = lrrotation(p); }
//         else if(bf(p)==2 && bf(p->left)==0){ p = llrotation(p); }
//         else if(bf(p)==-2 && bf(p->right)==-1){ p = rrrotation(p); }
//         else if(bf(p)==-2 && bf(p->right)==1){ p = rlrotation(p); }
//         else if(bf(p)==-2 && bf(p->right)==0){ p = llrotation(p); }

        
//         return p;
//     }

//      struct node* inpre(struct node* p){
//         while(p->right!=NULL)
//             p = p->right;
//         return p;    
//     }

//     struct node* insuc(struct node* p){
//         while(p->left!=NULL)
//             p = p->left;

//         return p;    
//     }

//     ~AVL(){

//     }
// };


// int main(){

//     AVL b;
//     int c,x;

//     do{
//         cout<<"\n1.Display levelorder on newline";
//         cout<<"\n2.Insert";
//         cout<<"\n3.Delete\n";
//         cout<<"\n0.Exit\n";
//         cout<<"\nChoice: ";

//         cin>>c;

//         switch (c)
//         {
//         case 1:
//             b.levelorder_newline();
//             // to print the tree in level order
//             break;
                  
//         case 2:
//             cout<<"\nEnter no. ";
//             cin>>x;
//             b.root = b.insert(b.root,x);
//             break;
        
//         case 3:
//             cout<<"\nWhat to delete? ";
//             cin>>x;
//             b.root = b.deleteNode(b.root,x);
//             break;
            
//         case 0:
//             break;
//         }

//      } while(c!=0);
  
// }