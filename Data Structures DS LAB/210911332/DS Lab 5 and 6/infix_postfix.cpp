#include <iostream>
#include <stdio.h>
using namespace std;

class stk
{
    int top, MAX;
    char infix[50];
    char arr[50];
    public:
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
        cout<<"Enter a infix expression"<<endl;
        gets(infix);
    }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }
    int prec(char c)
    {
        switch (c)
        {
        case '-':
        case '+':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        default:
            return 0;
        }
    }
    void conv()
    {
        char pfix[50];
        int l,p,precd;
        char e1,e2;
        p=0;
        for(int i=0;infix[i]!='\0';i++)
        {
            e1 = infix[i];
            // cout << i << "," << p <<","<<e1<<endl;
            switch(e1)
            {
            case '(':
                push(e1);
                break;
            case ')':
                e2 = pop();
                while(e2!='(')
                {
                    pfix[p++] = e2;
                    e2 = pop();
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if(!isEmpty())
                {
                    precd = prec(e1);
                    e2 = pop();
                    while(precd <= prec(e2))
                    {
                        pfix[p++]=e2;
                        if(!isEmpty())
                            e2 = pop();
                        else
                            break;
                    }
                    if(precd>prec(e2))
                        push(e2);
                }
                push(e1);
                break;
            default:
                pfix[p++] = e1;
                break;
            }
        }

        while(!isEmpty())
            pfix[p++] = pop();
        pfix[p] = '\0';
        cout << "The Postfix expression is " << pfix << endl;
    }

};
int main()
{
    stk exp;
    exp.read();
    exp.conv();
    return 0;
}
