
#include<iostream>
using namespace std;
int main()
{
    char c1[20], c2[20],c3[20];
int i,f1=0,f2=0,result=0,j=0;
cout<<"enter the string";
cin.getline(c1,20);
cout<<"enter the string";
cin.getline(c2,20);

for(i=0;c1[i]!='\0';i++)
{
    f1++;
}
for(i=0;c2[i]!='\0';i++)
{
    f2++;
}
while(c1[i]!='\0')
    i++;
while(c2[j]!='\0')
{
    c1[i]=c2[j];
    j++;
    i++;

}
cout<<"string="<<c1<<endl;;
return 0;
}
