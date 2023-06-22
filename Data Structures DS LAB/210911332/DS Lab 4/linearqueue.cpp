#include<iostream>
using namespace std;
class que{
int rear,front;
int size;
int *q;
public:
    que(int value)
    {
        rear=front=-1;
        size=value;
        q=new int[size];
    }

    void enqueue(int );
    int dequeue();
    void display();

};
void que::enqueue(int n)
{
    if(rear==size-1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    q[rear++]=n;
}
int que::dequeue()
{
    if(front==rear)
    {
        cout<<"Empty queue";
        return 0;
    }
    return q[++front];
}
void que::display()
{
    if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : "<<endl;
      for (int i = front; i < rear; i++)
      cout<<q[i]<<" ";
         cout<<endl;
   }
}
int main() {
   int ch;
   que o(50);
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch (ch) {
         case 1:
             int ele;
             cout<<"Enter element to be inserted";
             cin>>ele;
             o.enqueue(ele);
         break;
         case 2:
             o.dequeue();
         break;
         case 3: o.display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);
   return 0;
}
