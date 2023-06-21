#include<iostream>
#include<stack>
using namespace std;
int count;
int vertexreach;
void BFS(int v,int reach[],int a[][10],int label,int n)
{
    stack<int> Q;
    reach[v]=label;
    Q.push(v);
    vertexreach=1;
    cout<<v<<" ";
    while(!Q.empty()){
        int w;
        w=Q.top();
        Q.pop();
        for(int u=1;u<=n;u++){
            if(a[w][u]==1 && reach[u]!=1)
        {
            cout<<u<<" ";
            vertexreach++;
            Q.push(u);
            reach[u]=1;
        }}
    }
}
int main(void){
int a[10][10],n,m,x,v,label=1;
count=0;
cout<<"Enter number of vertices";
cin>>n;
cout<<"Enter number of edges";
cin>>m;
for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
    a[i][i]=0;}}
int p,q;

for(int i=1;i<=m;i++)
{
    cout<<"Enter source";
    cin>>p;
    cout<<"Enter destination";
    cin>>q;
    a[p][q]=1;
}
int reach[n+1];
for(int i=1;i<=n;i++){
    reach[i]=0;
}
for(int i=0;i<n;i++){

cout<<"Enter starting vertex";
cin>>v;
BFS(v,reach,a,label,n);
if(vertexreach==n){
    cout<<v<<"is a MOTHER VERTEX ";
}

}
cout<<"Visited vertices ";
for(int i=1;i<=n;i++){
        if(reach[i]!=0){
   cout<<" "<<i;}
}
}
