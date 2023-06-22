#include<iostream>
using namespace std;
#define MAX 100;
class sparse{
private:
    int ;
    int row,column,len;
public:
    sparse(int r,int c){
    row=r;
    column=c;
    len=0;
    data =new int[MAX];
    for(int i=0;i<MAX;i++)
        data[i]=new int[3];


    }


};
