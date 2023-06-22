#include<iostream>

using namespace std;
int main()
{
    char c[20];int i;
int f=0;
cout<<"enter the string";

cin.getline(c,20);
for(i=0;c[i]!='\0';i++)
{
    f++;
}
cout<<"string length ="<<f<<endl;

return 0;
}
