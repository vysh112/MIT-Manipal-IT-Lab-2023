
#include<iostream>
using namespace std;
int c=0;
int binarySearch(int arr[], int l, int r, int x)
{   c++;
    if (r >= l) {
        c++;
        int mid = l + (r - l) / 2;
        c++;

        if (arr[mid] == x){
            c++;
            return mid;}

        c++;
        if (arr[mid] > x){
            c++;
            return binarySearch(arr, l, mid - 1, x);}
        c++;
        return binarySearch(arr, mid + 1, r, x);
    }
    c++;
    return -1;
}

int main()
{
    int num;
    cout<<"Enter number of array elements:";
    cin>>num;
    int arr[num];
    cout<<"Enter array elements:";
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    cout<<"Enter element to search for:";
    int x ;
    cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    cout<<endl<<"COUNT IS "<<c;
    return 0;
}
