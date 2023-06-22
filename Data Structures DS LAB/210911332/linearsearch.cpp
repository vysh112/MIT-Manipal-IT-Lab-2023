











#include<iostream>
using namespace std;
int main()
{

    int pos,n,key,a[10];
    pos=-1;
    cout<<"Enter number of elements";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter element to be searched for";
    cin>>key;
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {

            pos=i+1;
            cout<<"Element found at pos"<<pos;

    }

}
if(pos==-1)
cout<<"Element not found";

}
