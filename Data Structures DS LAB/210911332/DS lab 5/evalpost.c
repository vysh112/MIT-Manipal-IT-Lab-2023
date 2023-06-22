#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int top=-1,s[20];

void push(int n)
{
  s[++top]=n;
}
int pop()
{
  return s[top--];
}

void main()
{
  char a[20],b[20];
  int i,j,x,op1,op2;
  clrscr();

  cout<<"Enter expression: ";
  gets(a);
  int l=strlen(a);
  int count=0;
  for(i=0;i<l;i++)
  {
    if(a[i]>=48 && a[i]<=57)
    {
      push(((int)a[i])-48);
    }
    if((a[i]>=65 && a[i]<=90)||(a[i]>=97 && a[i]<=122))
    {
      cout<<"Enter value for variable "<<a[i]<<": ";
      cin>>x;
      push(x);
    }
    if(a[i]==42 || a[i]==43 || a[i]==45 || a[i]==47 || a[i]==94)
    {
      op2=pop();
      op1=pop();
    }
    if(a[i]==42)
      push(op1*op2);
    if(a[i]==43)
       push(op1+op2);
    if(a[i]==45)
      push(op1-op2);
    if(a[i]==47)
      push(op1/op2);
    if(a[i]==94)
      push(pow(op1,op2));
  }
  cout<<"\nResult is: "<<pop();

}
