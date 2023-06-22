
#include<iostream>
using namespace std;
int main()
{
    char c1[20], c2[20],c3[20];
int i,f1=0,f2=0,result=0;
cout<<"enter the string";
cin.getline(c1,20);
cout<<"enter the string to insert";
cin.getline(c2,20);


while(c1[i]!='\0'||c2[i]!='\0')
{

    if(c1[i]!=c2[i])
    {

        result++;
    }
    i++;
}
if(result==0)
     cout<<"string equal";
else
    cout<<"string not equal";

return 0;
}

