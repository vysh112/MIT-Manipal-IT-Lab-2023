#include<iostream>
using namespace std;
int main(){
char m[100];char s[100];
int p,l1,l2;
cout<<"Enter a main string";
gets(m);
cout<<"Enter a substring";
gets(s);
cout<<"Enter position to insert substring";
cin>>p;
    for(l1=0;m[l1]!='\0';l1++)
    {

    }
    cout<<"Length of first string is"<<l1;

    for(l2=0;s[l2]!='\0';l2++)
    {

    }
  cout<<"Length of substring is"<<l2;

  for(int i=l1;i>=p;i--)
  {

      m[i+l2]=m[i];
  }
  for(int i=0;i<l2;i++)
  {
      m[i]=s[p+i];
  }
  m[l1+l2]='\0';
  for(int i=0;m[i]!='\0';i++)

  {cout<<m[i];}
}
