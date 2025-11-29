#include <iostream>
using namespace std;
#define n 5

void insertionSort(int arr[n]){

    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        int key = arr[i];

        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }
    
}

int main(){

    int arr[n] = {3, 2, 5, 4, 6};

    insertionSort(arr);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}