#include<iostream>

using namespace std;
int selectionsort(int a[],int n)
{
int i,j,temp;
int min_in;
for(i=0;i<n-1;i++)
{
    min_in=i;
    for(j=i+1;j<n;j++)
    {
        if(a[j]<a[min_in])
        {
            min_in=j;
            temp=a[i];
            a[i]=a[min_in];
            a[min_in]=temp;
    }


}
}
}
int main()
{
    int a[]={1,5,3,2,5,76,86,92},n;
     n = sizeof(a)/sizeof(int);
    cout<<"sorted array is";
    selectionsort(a,n);
    for(int i=0;i<n;i++)
{
    cout<<a[i]<<endl;
}
return 0;
}
