#include <iostream>
using namespace std;
class  Node{
    public:
    int data;
    Node *next;
};

class Stack{
    private:
    Node *top;
    public:
    Stack(){
        top=NULL;
    }
    void push(int elem){
        Node *temp= new Node;
        temp->data=elem;
        temp->next=top;
        top=temp;
    }

    int pop(){
        if(top==NULL){
            cout<<"Empty Stack!"<<endl;
            return 0;
        }
        Node *trav=top;
        int elem;
        elem=top->data;
        top=top->next;
        delete trav;
        return elem;
    }

    int peek(){
        if(top==NULL){
            cout<<"Empty Stack!"<<endl;
            return 0;
        }
        return top->data;
    }

    void display(){
        Node *trav= top;

        while(trav){
            cout<<trav->data<<" ";
            trav=trav->next;
        }
    }
};

class Queue{
    private:
    Node *front, *rear;
    public:
    Queue(){
        front=rear=NULL;
    }

    void enqueue(int elem){
        Node *temp= new Node;
        temp->data=elem;
        temp->next=NULL;
        if(!front){
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
        return;
    }

    int dequeue(){
        if(!front){
            return 0;
        }
        Node *trav=front;
        int elem=trav->data;
        front=trav->next;
        if(front==NULL)
            rear=NULL;
        delete trav;
        return elem;
    }

    void display(){
        Node *trav= front;

        while(trav){
            cout<<trav->data<<" ";
            trav=trav->next;
        }

    }
};

int main(){
    Queue q;
    int n=0,ele;
    Stack s;
    cout<< "Queue"<<endl;
     while(n!=-1)
     {
         cout<< "Enter 1 to insert"<<endl;
         cout<< "Enter 2 to delete"<<endl;
         cout<< "Enter 3 to display"<<endl;
         cin>>n;
         switch(n)
         {
             case 1:{
                 cout<< "Enter the element "<<endl;;
                 cin>>ele;
                 q.enqueue(ele);
                 break;
             }
             case 2:
                {
                    ele=q.dequeue();
                    cout<< "The deleted element is "<<ele<<endl;
                    break;
                }
             case 3:
                {
                    q.display();
                    break;
                }
         }
     }
     n=0;
     cout<< "Stack"<<endl;
     while(n!=-1)
     {
         cout<< "Enter 1 to insert"<<endl;
         cout<< "Enter 2 to delete"<<endl;
         cout<< "Enter 3 to display"<<endl;
         cin>>n;
         switch(n)
         {
         case 1:
            {
                cout<< "Enter the element "<<endl;;
                 cin>>ele;
                 s.push(ele);
                 break;

            }
              case 2:
                {
                    ele=s.pop();
                    cout<< "The deleted element is "<<ele<<endl;
                    break;
                }
                case 3:
                {
                    s.display();
                    break;
                }

         }

     }
}
