
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int i, j,temp;
    for (i = 0; i < n - 1; i++)


        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                {
                 temp=arr[j];
                 arr[j]=arr[j+1];
                 arr[j+1]=temp;
                }
}

void printArray(int arr[], int sz)
{
    int i;
    for (i = 0; i < sz; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 9, 1, 6, 2, 7,74};
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}
