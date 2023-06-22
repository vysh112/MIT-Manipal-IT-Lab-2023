#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class stk
{
    int top, MAX;
    char arr[];
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
    void conv(char infix[])
    {
        char pfix[50];
        int l,p,precd;
        char e1,e2;
        p=0;
        for(int i=strlen(infix)-1;i>=0;i--)
        {
            e1 = infix[i];
            // cout << i << "," << p <<","<< infix[i] <<endl;
            switch(e1)
            {
            case ')':
                push(e1);
                break;
            case '(':
                e2 = pop();
                while(e2!=')')
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
                    //if(precd>prec(e2))
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
        char temp;
        int i,j,num;
        num = strlen(pfix);
        for(i = 0, j = num - 1; i < num/2; i++, j--)  
        {     
        temp = pfix[i];  
        pfix[i] = pfix[j];  
        pfix[j] = temp;  
        }  
        cout << "The Prefix expression is " << pfix << endl;
    }

};
int main()
{
    stk exp;
    char infix[50];
    cout<<"Enter a infix expression"<<endl;
    gets(infix);
    exp.conv(infix);
    return 0;
}
