// Implement selection sort to sort an array of integers in ascending order

#include<iostream>

using namespace std;

int SelectionSort(int* arr,int n){
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cout<<"Enter the size of the array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    SelectionSort(arr,n);

    cout << "The sorted array is";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}

/*

Output

Enter the size of the array 4
5 6 4 5
The sorted array is 4 5 5 6 

*/


