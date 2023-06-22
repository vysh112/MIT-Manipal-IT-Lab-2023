#include <iostream>
using namespace std;

struct Node{
    Node *lc, *rc;
    int data;
};

class Tree{
    private:
    Node *root;
    public:
    Tree(){
        root= createTree();
    }
    Node* createTree(){
        int val;
        cout<<">";
        cin>>val;
        if(val==-1)
            return NULL;
        Node *temp= new Node;
        temp->data=val;
        cout<<"Left child of "<<val<<endl;
        temp->lc=createTree();
        cout<<"Right child of "<<val<<endl;
        temp->rc=createTree();
    }

    void Inorder(Node *node){
        if (node==NULL){
            return;
        }
        Inorder(node->lc);
        cout<<node->data<<" ";
        Inorder(node->rc);
    }

    void print(){
        Inorder(root);
    }
};

int main(){
    cout<<"Enter root of tree:";
    Tree t1;
    cout<<"Binary tree is:";
    t1.print();
}
