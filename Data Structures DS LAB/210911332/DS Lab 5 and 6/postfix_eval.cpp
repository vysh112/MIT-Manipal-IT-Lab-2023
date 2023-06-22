#include <iostream>
#include <stdio.h>
using namespace std;

class stk
{
    public:
    int top, MAX;
    char pfix[50];
    char arr[50];
    stk()
    {
        top = -1;
        MAX = 50;
    }

    void push(char i)
    {
        if(top == MAX-1)
        {
            cout<< "Stack Overflow"<<endl;
            return;
        }
        arr[++top]=i;
    }
    int pop()
    {
        if(top==-1)
        {
            cout<< "Stack Underflow"<<endl;
            return -1;
        }
        return arr[top--];
    }
    void read()
    {
        cout<<"Enter a postfix expression"<<endl;
        gets(pfix);
    }

    int calc(int a, int b, char c)
    {
        switch(c)
        {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        }
    }

    void eval()
    {
        int op1,op2, res;
        for(int i=0;pfix[i]!='\0';i++)
        {
            if(pfix[i]=='+'||pfix[i]=='-'||pfix[i]=='*'||pfix[i]=='/')
            {
                op2 = pop();
                op1 = pop();
                res = calc(op1, op2, pfix[i]);
                push(res);
            }
            else
            {
                push(pfix[i]-'0');
            }
        }
        cout << pop() ;
    }

};
int main()
{
    stk exp;
    exp.read();
    exp.eval();
    return 0;
}
