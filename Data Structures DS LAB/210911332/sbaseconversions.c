#include<iostream>
#define MAX 10
using namespace std;
class stk{
private:
    int top;
    int s[MAX];
public:
    stk(){
    top=-1;}

    void push(int ele);
    int pop();
    void display();
};
void stk::push(int ele){
if(top==MAX-1){
    cout<<"Stack overflow";
    return;
}
top=top+1;
s[top]=ele;
}
int stk::pop(){
if(top==-1){

    cout<<"Stack underflow";
    return -1;
}
return s[top--];

}

void stk::display()
{
int i;
if(top==-1)
{
     cout<<"Stack underflow condition";


}
for(i=0;i<10;i++){
    cout<<s[i];
}}
int main(){
stk a;
int d;
int i=0;
cout<<"Enter stack elements";
for(i=0;i<10;i++)
{cin>>d;
a.push(d);}
a.display();

}

