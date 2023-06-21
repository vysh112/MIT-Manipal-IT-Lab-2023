
#include <iostream>
using namespace std;
int c=0;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    c++;
    for (i = 0; i < n-1; i++)
    {   c++;
        c++;
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
          c++;
          c++;
          if (arr[j] < arr[min_idx]){
              c++;
              min_idx = j;}
        }
        c++;
        c++;
        if (min_idx!=i){
            c=c+3;
            swap(&arr[min_idx], &arr[i]);}
    }
    c++;
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
      cout << arr[i] << " ";
      cout << endl;
    }
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
    int n = num;
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    cout<<"COUNT IS"<<endl<<" "<<c;
    return 0;
}
