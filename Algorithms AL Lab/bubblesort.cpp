#include<iostream>
using namespace std;
int c=0;
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++){
        c++;
        for (j = 0; j < n - i - 1; j++){
            c++;
            c++;
            if (arr[j] > arr[j + 1]){
                c++;
                swap(arr[j], arr[j + 1]);}}}
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
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
    int N = num;
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    cout<<endl<<"COUNT IS"<<c;
    return 0;
}
