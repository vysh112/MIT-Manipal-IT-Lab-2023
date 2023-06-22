#include<iostream>
using namespace std;
int main()
{

int a[100][100],b[100][100],m1,n1,m2,n2;
cout<<" Enter number of rows of m1";
cin>>m1;
cout<<"columns";
cin>>n1;
cout<<"Enter elements";
for(int i=0;i<m1;i++)
    for(int j=0;j<n1;j++)
    cin>>a[i][j];
cout<<"Entered matrix is \n";
for(int i=0;i<m1;i++)
   {

   for(int j=0;j<n1;j++)
    {cout<<a[i][j]<<"\t";}
    cout<<endl;
   }
cout<<" Enter number of rows of m2";
cin>>m2;
cout<<"columns";
cin>>n2;
cout<<"Enter elements";
for(int i=0;i<m2;i++)
    for(int j=0;j<n2;j++)
    for(int j=0;j<n2;j++)
    cin>>a[i][j];
cout<<"Entered matrix is \n";
for(int i=0;i<m2;i++)
   {

   for(int j=0;j<n2;j++)
    {cout<<a[i][j]<<"\t";}
    cout<<endl;
   }

}
