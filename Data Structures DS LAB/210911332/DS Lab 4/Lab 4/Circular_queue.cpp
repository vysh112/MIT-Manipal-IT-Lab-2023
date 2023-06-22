#include <iostream>
#define SIZE 5
using namespace std;
class Queue {
    private:
       int que[SIZE],f,r;
    public:
       Queue(){
           f=-1;
           r=-1;
        }
    void insert(int val){
        if((r+1)%SIZE==f)
            cout<<"Queue is full"<<endl;
        else{
        if(f==-1)
            f=r=0;
        else if(r==SIZE-1 && f!=0)
            r=0;
        else
            r++;
        que[r]=val;
        cout<<"Inserted:"<<val<<endl;
        }
    }
    void del(){
        if((f==-1)&&(r==-1)){
            cout<<"Queue is empty"<<endl;
        }
        else{
            int ele=que[f];
            if(f==r){
                f=-1;
                r=-1;
            }
            else
                f=(f+1)%SIZE;
            cout<<"Deleted:"<<ele<<endl;
        }
    }
    void display(){
        cout<<"Queue:"<<endl;
        int count=((r+SIZE-f)%SIZE)+1;
        int i;
        for(i=0;i<count;i++){
            cout<<que[(f+i)%SIZE]<<endl;
        }
    }
};
int main()
{
    Queue q1;
    q1.del();
    q1.insert(1);
    q1.insert(2);
    q1.insert(3);
    q1.insert(4);
    q1.insert(5);
    q1.insert(6);
    q1.del();
    q1.del();
    q1.display();
    q1.del();
    q1.insert(10);
    q1.insert(11);
    q1.display();
    return 0;
}
