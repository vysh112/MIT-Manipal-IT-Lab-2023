#include<iostream>
using namespace std;
class stack{
private:
    int MAX=10;
    int top;
    char s[10];
public:
    stack(){
    top=-1;
    }
    void push(char x);
    char pop();
    void display();
    void palindrome();
};
void stack::push(char x){
if(top==MAX-1){

    cout<<"Stack is full";
    return;
}
top=top+1;
s[top]=x;

}

char stack::pop(){
if(top==-1){

    cout<<"Stack underflow condition";
    return -1;
}
return s[top--];

}

void stack::display()
{
int i;
if(top==-1)
{
     cout<<"Stack underflow condition";


}
for(i=0;i<10;i++){
    cout<<s[i];
}}
void stack::palindrome(){
int l=0;
int c=0;
char p;
p=pop();
for(l=0;l<10;l++)
{


if(p!=s[l])
{
    c=-1;
}


}
if(c==0)

    cout<<"Palindrome";

else
    cout<<"Not a palindrome";

}


int main(){
stack a;
char d;
int i=0;
cout<<"Enter stack elements";
for(i=0;i<10;i++)
{cin>>d;
a.push(d);}
a.display();
a.palindrome();
}
