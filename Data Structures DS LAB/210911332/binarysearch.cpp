#include<iostream>
using namespace std;
int BinSearch(int a[],int n,int key)
{
       int max,min,mid;
        max=n;
        min=0;
    while(max>=min)
    {

        mid=(max+min)/2;
        if(a[mid]==key)
            {cout<<"Element present at pos";
            return mid+1;}
        else if(key>a[mid])
            min=mid+1;
        else
            max=mid-1;

    }
    cout<<"element not present";

}
int main()
{

int a[100],n,mid,pos,key;
    pos=-1;
    cout<<"Enter number of elements";
    cin>>n;
    cout<<"Enter sorted array";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter element to be searched for";
    cin>>key;
    cout<<BinSearch(a,n,key);
    return 0;
}
