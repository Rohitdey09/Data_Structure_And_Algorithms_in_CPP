#include<iostream>

using namespace std;

int bubblesort(int* arr,int n){
    for(int pass=1;pass<=n-1;pass++){
        for(int j=0;j<=n-pass-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cout<<"Enter the size of the array ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bubblesort(arr,n);

    cout << "The sorted array is ";
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

