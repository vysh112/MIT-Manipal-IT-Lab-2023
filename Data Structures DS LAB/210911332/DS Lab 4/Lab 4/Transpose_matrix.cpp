#include<iostream>
using namespace std;

class spm{
  int r,c,v;

  public:

  void read(spm a[]){

      int ele;
      int k=1,m,n,i,j;
    cout<<"Enter the size of the  array";
  cin>>m>>n;
  cout<<"Enter the elements of the array";
  for(i=0;i<m;i++){
   for(j=0;j<n;j++){
    cin>>ele;
    if(ele==0)
        continue;
    a[k].r=i;
    a[k].c=j;
    a[k].v=ele;
    k++;
   }
  }


    a[0].r=m;
    a[0].c=n;
    a[0].v=k-1;

  }



void transpose(spm a[],spm b[]){
    int rt[50],k=0;

    b[0].r=a[0].c;
    b[0].c=a[0].r;
    b[0].v=a[0].v;
    int i,j;
    for(i=0;i<a[0].c;i++)
        rt[i]=0;
    for(i=1;i<=a[0].v;i++)
        rt[a[i].c]++;

    int sp[50];
    sp[0]=1;
    for(i=1;i<a[0].c;i++)
        sp[i]=sp[i-1] +rt[i-1];

         for(i=1;i<=a[0].v;i++)
         {
            k=sp[a[i].c]++;
            b[k].r=a[i].c;
               b[k].c=a[i].r;
                  b[k].v=a[i].v;
         }


}

void display(spm b[]){
  cout<<"The transpose of sparse matrix:"<<endl;
  cout<<endl;
  cout<<"Index"<<"\t";
    cout<<"Rows"<<"\t";
      cout<<"Columns"<<"\t";
        cout<<"Values"<<endl;

        for(int i=0;i<=b[0].v;i++)
        {
            cout<<i<<"\t";
            cout<<b[i].r<<"\t";
            cout<<b[i].c<<"\t";
            cout<<b[i].v<<endl;
        }


}
};

int main(){
  spm a[50],a1,b[50];
  a1.read(a);
  a1.transpose(a,b);
  a1.display(b);











return 0;
}
