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

        for(int i=top;i>=0;i--){
            if(s[i]<=10)
                cout<<s[i];
            else
            {
                char c=s[i]+55;
                cout<<c;
            }

        }
    }
int main(){
stk a;
int numb;
cout<<"Enter a number";
cin>>numb;
int div,base;
cout<<"Enter the base";
cin>>base;
do{
    div=numb%base;
    numb=numb/base;
    a.push(div);

} while(numb>=base);
a.push(numb);
a.display();

}
