#include <bits/stdc++.h>
using namespace std;
#define MAX 20
class stk1
{
    public :
    int top;
    char a[MAX][40];

    stk1()
    {
        top=-1;
    }

    bool isempty()
    {
        if (top==-1)
        return true;
        return false;
    }

    bool isfull()
    {
        if (top==MAX-1)
        return true;
        return false;
    }

    void push(char c[])
    {
        if (isfull())
        {
            cout<<"STACK FULL"<<endl;
            return ;
        }
        else
        {
            int i;
            top++;
            for ( i=0;i<strlen(c);i++)
            {
                a[top][i]=c[i];
            }
            a[top][i]='\0';
        }
    }

    void pop(char p[])
    {
        if (isempty())
        {
            cout<<"STACK EMPTY"<<endl;
            return ;
        }
        else
        {
            int i;
            for ( i=0;i<strlen(a[top]);i++)
            {
                p[i]=a[top][i];
            }
            p[i]='\0';
            top--;
        }
    }
};

class stk
{
    public :
    int top;
    char a[MAX];

    stk()
    {
        top=-1;
    }

    bool isempty()
    {
        if (top==-1)
        return true;
        return false;
    }

    bool isfull()
    {
        if (top==MAX-1)
        return true;
        return false;
    }

    void push(char c)
    {
        if (isfull())
        {
            cout<<"STACK FULL"<<endl;
            return ;
        }
        else
            a[++top]=c;
    }

    void pop()
    {
        if (isempty())
        {
            cout<<"STACK EMPTY"<<endl;
            return ;
        }
        else
            top--;
    }

    char topp()
    {
        if (isempty())
        return '\0';
        return a[top];
    }

};


void fullyparenthesis(char ex1[], char op , char ex2[],char re[])
{
    int c1=strlen(ex1);
    int c2=strlen(ex2);
    int relen=strlen(ex1)+strlen(ex2)+3;
    int k=0;
    re[k++]='(';
    int h=0;
    while(k<=c1)
    re[k++]=ex1[h++];
    re[k]='\0';
    re[k++]=op;
    re[k]='\0';
    int g=0;
    while(ex2[g]!='\0')
    re[k++]=ex2[g++];
    re[k]='\0';
    re[k++]=')';
    re[k]='\0';
}


void convert_to_fulexp(char t[]){
    stk1 s;
    int n=strlen(t);
    for (int i=0;i<n;i++)
    {
        char z=t[i];
        if (z>=97 && z<=122) {
        char w[3];
        w[0]=z;
        w[1]='\0';
        s.push(w); }
        else if (z=='+' || z=='-' || z=='*' || z=='/')
        {
            char e1[30],e2[30];
            s.pop(e1);
            s.pop(e2);
            char fin[40];
            switch(z)
            {
                case '+':
                {
                    fullyparenthesis(e1,z,e2,fin);
                    s.push(fin);
                    break;
                }
                case '-':
                {
                    fullyparenthesis(e1,z,e2,fin);
                    s.push(fin);
                    break;
                }
                case '/':
                {
                    fullyparenthesis(e1,z,e2,fin);
                    s.push(fin);
                    break;
                }
                case '*':
                {
                    fullyparenthesis(e1,z,e2,fin);
                    s.push(fin);
                    break;
                }
            }
        }
    }
    char ans[50];
    s.pop(ans);
    cout<<ans<<endl;
    int o;
    for (o=0;o<strlen(ans);o++)
    {
        t[o]=ans[o];
    }
    t[o]='\0';
}

void reverss(char y[])
{
    char q[20];
    int l=strlen(y);
    int j=0;
    for (int i=l-1;i>=0;i--)
    {
        if (y[i]=='(') {
        q[j++]=')'; continue; }
        else if (y[i]==')') {
        q[j++]='('; continue; }
        q[j++]=y[i];
    }
    int i;
    for ( i=0;i<l;i++)
    y[i]=q[i];
    y[i]='\0';
}

int precedence(char r)
{
    switch (r)
    {
        case '+' :
        case '-' : return 1;
        case '*' :
        case '/' : return 2;
        default : return -1;
    }
}

int main()
{
    //char arr[]="-w+c*ab";
    char arr[100];
    cout<<"Prefix form : ";
    cin>>arr;
    reverss(arr);
    cout<<"Infix form : ";
    convert_to_fulexp(arr);

    stk s;
    char ans[20];
    int j=0;
    int h=strlen(arr);
    int i=0;
    while (h--)
    {
        char c=arr[i++];
        if ((c>=97 && c<=122))
        ans[j++]=c;
        else if (c=='(')
        s.push(c);
        else if (c==')')
        {
            while (s.topp()!='(')
            {
                ans[j++]=s.topp();
                s.pop();
            }
            s.pop();
        }
        else
        {
            if (s.isempty())
            s.push(c);
            else if (precedence(c)>precedence(s.topp()) )
            s.push(c);
            else
            {
                while (!s.isempty())
                {
                    if (precedence(c)>precedence(s.topp()))
                    break;
                    ans[j++]=s.topp();
                    s.pop();
                }
                s.push(c);
            }
        }
    }
    while (!s.isempty())
    {
        ans[j++]=s.topp();
        s.pop();
    }
    ans[j]='\0';
    cout<<"Postfix form : "<<ans<<endl;
    return 0;
}
