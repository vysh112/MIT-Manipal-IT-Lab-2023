#include<iostream>
#include<string.h>
using namespace std;
class student{
private:
    char name[100];
    char grade;
    int rn;
public:
    void read(student arr, int n)
    {
        for(int i=0;i<n;i++)
        cout<<"Enter name";
        cin>>arr[i].name;
        cout<<"Enter grade";
        cin>>arr[i].grade;
        cout<<"Enter roll number";
        cin>>arr[i].rn;

    }
    void display(student arr, int n)
    {

  for(int i=0;i<n;i++)
        cout<<" name";
        cout<<arr[i].name;
        cout<<" grade";
        cout<<arr[i].grade;
        cout<<" roll number";
        cout<<arr[i].rn;
    }

};

int main()
{
    student arr[100],s;
    cout<<"Enter size of array ";
    cin>>n;
    s.read(arr,n);
    s.display(arr,n);
}
