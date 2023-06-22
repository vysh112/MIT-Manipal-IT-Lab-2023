#include<iostream>
#include<string.h>
using namespace std;
int main(){
char s1[100];char s2[100];
int l1,l2;
cout<<"Enter two strings to compare";
gets(s1);
gets(s2);
l1=strlen(s1);
l2=strlen(s2);
int i=0,chk=0,dif=0;
 while(s1[i]!='\0' || s2[i]!='\0')
    {
        if(s1[i]!=s2[i])
        {
            chk = 1;
            dif=s1[i]-s2[i];
            break;
        }
        i++;
    }
    if(chk==0)
        cout<<"\nStrings are Equal";
    else
        cout<<"\nStrings are not Equal and their difference is"<<dif;
    cout<<endl;
    return 0;

}












