#include<iostream>
#include<stack>
using namespace std;
int main(void){
int a[10][10],n,m,x,v,label=1;
int b[10][10];
cout<<"Enter number of vertices";
cin>>n;
cout<<"Enter number of edges";
cin>>m;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
    a[i][j]=0;
    b[i][j]=0;
}}
int p,q;

for(int i=1;i<=m;i++)
{
    cout<<"Enter source";
    cin>>p;
    cout<<"Enter destination";
    cin>>q;
    a[p][q]=1;
    b[q][p]=1;
}
cout<<"Transposed matrix"<<endl;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        cout<<b[i][j]<<" ";
    }
    cout<<endl;
}
}
