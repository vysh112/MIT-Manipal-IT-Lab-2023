#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class stk
{
    int top, MAX;
    char arr[][25];
    public:
    stk()
    {
        top = -1;
        MAX = 50;
    }

    void push(char i[])
    {
        if(top == MAX-1)
        {
            cout<< "Stack Overflow"<<endl;
            return;
        }
        strcpy(arr[++top],i);
    }
    char* pop()
    {
        if(top==-1)
        {
            cout<< "Stack Underflow"<<endl;
            return " ";
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
    void conv(char pfix[])
    {
        int l,p,precd;
        char s[20], t[20];
        char *op1,*op2;
        for(int i=strlen(pfix)-1;i>=0;i--)
        {
            switch(pfix[i])
            {
            case '+':
            case '-':
            case '*':
            case '/':
                op1 = pop();
                op2 = pop();
                strcpy(s,"(");
                strcat(s,op1);
                t[0]=pfix[i];
                t[1]='\0';
                strcat(s,t);
                strcat(s,op2);
                strcat(s,")");
                push(s);
                break;
            default:
                s[0] = pfix[i];
                s[1] = '\0';
                push(s);
                break;
            }
            //cout << i << "," << pfix[i] <<", "<< arr[0]<<endl;
        }

        cout << "The Infix expression is " << pop() << endl;
    }
};

int main()
{
    stk exp;
    char pfix[50];
    cout << "Enter a prefix expression" << endl;
    cin >> pfix;
    exp.conv(pfix);
    return 0;
}