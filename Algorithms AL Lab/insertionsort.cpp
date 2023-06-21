#include <bits/stdc++.h>
using namespace std;
int c=0;
void insertionSort(int arr[], int n)
{   c++;
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        c++;
        c++;
        key = arr[i];
        c++;
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            c++;
            c++;
            arr[j + 1] = arr[j];
            c++;
            j = j - 1;
        }
        c++;
        c++;
        arr[j + 1] = key;
    }
    c++;
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
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
    insertionSort(arr, N);
    printArray(arr, N);
    cout<<"COUNT IS "<<endl<<c;

    return 0;
}
