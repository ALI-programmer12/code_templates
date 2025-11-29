#include <iostream>
using namespace std;

void merge(int arr[], int s, int e){

    int mid = s + (e-s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;


    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    //copy the values
    int mainArrIndex = s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainArrIndex++];
    }
    mainArrIndex = mid+1;
    for (int i = 0 ; i < len2; i++)
    {
        arr2[i] = arr[mainArrIndex++];
    }
    
    int index1 = 0;
    int index2 = 0;
    mainArrIndex = s;

    while (index1 < len1 && index2<len2)
    {
        //pick small one
        if (arr1[index1] < arr2[index2])
        {
            arr[mainArrIndex++] = arr1[index1++];
        }
        else
        {
            arr[mainArrIndex++] = arr2[index2++];
        }
        
    }

    while (index1 < len1)
    {
        arr[mainArrIndex++] = arr1[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrIndex++] = arr2[index2++];
    }
    

}

void mergeSort(int arr[], int s, int e){

    if(s>=e) return;

    int mid = s+(e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);   
}
 
int main() {
    
    int arr[12] = {5, 2, 3, 6, 1, 4, 99, 3, 2, 33, 3, 3};
    int n = 12;

    mergeSort(arr, 0, n-1);

    for (int i = 0; i < n-1; i++)
    {
        cout << arr[i] <<" "; 
    }
    
    return 0;
}