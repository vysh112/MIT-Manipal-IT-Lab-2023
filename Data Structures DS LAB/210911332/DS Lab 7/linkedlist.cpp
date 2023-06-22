#include<iostream>
using namespace std;
class Node{
public:
int data;
Node* next;

Node(){
data=0;
next=NULL;}

Node(int data){
this->data=data;
this->next=NULL;
}
};
class LinkedList{
public:
Node* head;

    LinkedList(){
    head=NULL;
    }

    void insertatend(int ele){
        Node* newNode= new Node();
        newNode->data=ele;
        newNode->next=NULL;
        if(head==NULL){

            head=newNode;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    void deleteatend() {
      if(head != NULL) {
        if(head->next == NULL) {
          head = NULL;
        } else {
          Node* temp = head;
          while(temp->next->next != NULL)
            temp = temp->next;
          Node* lastNode = temp->next;
          temp->next = NULL;
          free(lastNode);
        }
      }
    }
        void display(){
        Node *temp1=head;
        if(temp1!=NULL){
            cout<<"The list contains: ";
        while(temp1!= NULL) {
          cout<<temp1->data<<"-> ";
          temp1 = temp1->next;
        }}
        else {
        cout<<"The list is empty.\n";
      }
    }
void deleteAlternateNodes() {
   if (head == NULL)
      return;
   Node *prev = head;
   Node *node = head->next;
   while (prev != NULL && node != NULL) {
      prev->next = node->next;
      free(node);
      prev = prev->next;
      if (prev != NULL) {
         node = prev->next;
      }
   }
}
    };


int main(){
  LinkedList MyList;

  //Add three elements at the end of the list.
  MyList.insertatend(10);
  MyList.insertatend(20);
  MyList.insertatend(30);
  MyList.insertatend(30);
  MyList.display();

  MyList.deleteAlternateNodes();

  MyList.display();

  return 0;
}

