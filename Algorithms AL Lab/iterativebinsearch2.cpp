#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x, int count)
{
    while (l <= r) {
        count++;
        count++;
        int m = l + (r - l) / 2;
        count++;
        if (arr[m] == x){
            count++;
            cout<<"Count is"<<count<<endl;
            return m;}
        count++;
        if (arr[m] < x){
            count++;
            l = m + 1;}
        else{
            count++;
            r = m - 1;}
    }
    count++;
    return -1;
}

int main(void)
{   int count=0;
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
    int n = num;
    int result = binarySearch(arr, 0, n - 1, x,count);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}

