#include<iostream>
using namespace std;
class que{
private:
    int rear,front,size;
    int *arr;
public:
    que(int size){
    arr=new int[size];
    front=rear=-1;}
    void enqueue(int);
    int dequeue();
    void display();
};
void que::enqueue(int value)

{
    if((rear==size-1&&front==0)||(rear==front-1))
    {
        cout<<"Queue is full";
        return ;
    }
      else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
    }
int que::dequeue()
{
if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return 0 ;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;

    return data;

}
void que::display()
{
    if (front == -1)
    {
        cout<<"\nQueue is Empty";
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<<endl<<arr[i];
    }
    else
    {
        for (int i = front; i < size; i++)
            cout<<"%d "<<arr[i];

        for (int i = 0; i <= rear; i++)
            cout<<endl<<arr[i];
    }
}
int main()
{
    que o(5);
    int ch;

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
