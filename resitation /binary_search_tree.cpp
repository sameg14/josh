#include "iostream"
using namespace std;

class node{
public:
    int key_value;
    node(int v);
    node* left;
    node* right;
};

node::node(int v){
    key_value=v;
    left=NULL;
    right=NULL;
}

class btree{
public:
    btree();
    ~btree();
    node* root;
    void insert(int key, node* leaf);
    void print();
    void destory_tree(node* leaf);
    void preorderprint(node *leaf);
    int max_depth(node* leaf);//the number of nodes along the longest path from node leaf
    int min_value(node* leaf);//return the min value found in the tree
    void print_path(node* node);
    void printpathrecur(node* node, int path[], int pathlen);
    bool issametree(node* n1, node* n2);
};

btree::btree(){
    root=NULL;
}
btree::~btree(){
    destory_tree(root);
}
void btree::destory_tree(node* leaf){
    if(leaf!=NULL){
        destory_tree(leaf->left);
        destory_tree(leaf->right);
        cout<<"delete "<<leaf->key_value<<endl;
        delete leaf;
    }
}
void btree::insert(int key, node* leaf){
    if(root!=NULL){
        if(key<leaf->key_value){
            if(leaf->left!=NULL)
                insert(key, leaf->left);
            else{
                leaf->left=new node(key);
            }
            
        }
        else{
            if(leaf->right!=NULL){
                insert(key, leaf->right);
            }
            else{
                leaf->right=new node(key);
            }
        }
    }
    else{
        root=new node(key);
    }
}

void btree::preorderprint(node *leaf) {
    // The item in the root is printed first, followed by the
    // items in the left subtree and then the items in the
    // right subtree.
    if ( leaf != NULL ) {
        cout << leaf->key_value << " ";
        preorderprint( leaf->left );
        preorderprint( leaf->right );
    }
}
void btree::print(){
    cout<<"pre order print: "<<endl;
    preorderprint(root);
    cout<<endl;
}
int btree::max_depth(node* leaf){
    if(leaf==NULL)
        return 0;
    int leftsub, rightsub;
    leftsub=max_depth(leaf->left);
    rightsub=max_depth(leaf->right);
    if(leftsub>rightsub)
        return leftsub+1;
    else
        return rightsub+1;
}
int btree::min_value(node* leaf){
    while (leaf->left!=NULL) {//find the leftmost leaf
        leaf=leaf->left;
    }
    return (leaf->key_value);
}
void btree::print_path(node* leaf){
    int path[100];
    printpathrecur(leaf, path, 0);
}
void btree::printpathrecur(node* node, int path[], int pathlen){
    if(node==NULL)
        return;
    path[pathlen]=node->key_value;
    pathlen++;
    if(node->left==NULL && node->right==NULL){
        cout<<"print path: ";
        for(int i=0; i<pathlen; i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    else{
        printpathrecur(node->left, path, pathlen);
        printpathrecur(node->right, path, pathlen);
    }
}
bool btree::issametree(node* n1, node* n2){
    if(n1==NULL && n2==NULL)
        return true;
    else if(n1!=NULL && n2!=NULL){
        return (n1->key_value==n2->key_value) && issametree(n1->left, n2->left) && issametree(n1->right, n2->right);
    }
    else
        return false;//one is empty; one is not

}


int main(){
    btree b;
    b.insert(10, b.root);
    b.insert(14, b.root);
    b.insert(6, b.root);
    b.insert(4, b.root);
    b.insert(8, b.root);
    b.print();
    cout<<"max depth: "<<b.max_depth(b.root)<<endl;
    cout<<"min value: "<<b.min_value(b.root)<<endl;
    b.print_path(b.root);
    btree t;
    t.insert(10, t.root);
    t.insert(14, t.root);
    t.insert(6, t.root);
    t.print();
    cout<<b.issametree(b.root, t.root)<<endl;
    cout<<b.issametree(b.root, b.root)<<endl;
    return 0;
}