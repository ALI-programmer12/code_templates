#include<iostream>
using namespace std;
int main(){
    int count=0;
    bool flag = false;
    int n=16;
    int a[] ={31,2, 33, 4, 8, 29, 17, 19, 25, 27, 28, 9, 30, 1, 32, 3};
   
    cout<<"Before Sorting: \n";
    for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
    }
   
    for (int i=0; i<n-1;i++){
        for(int j=0; j<n-1-i;j++){
            count++;
            if(a[j] > a[j+1]){
                flag = true;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag ==false){
            break;
        }
    }
    cout<<"\n\nAfter Sorting: \n";
    for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
    }
    cout<<"\nCount is: "<<count<<endl;
}