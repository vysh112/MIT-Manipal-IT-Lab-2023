#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* createList(){
    Node *temp= new Node;
    cout<<"Enter the element\nEnter -1 to stop creating"<<endl;
    int elem;
    cin>>elem;
    if(elem==-1)
        return NULL;
    else{
        temp->data=elem;
        temp->next=createList();
        return temp;
    }
}

void traverse(Node *temp){
    cout<<temp->data<<" ";
    if(temp->next)
        traverse(temp->next);
    return;
}

int main(){
    Node *head=createList();
    traverse(head);
}
