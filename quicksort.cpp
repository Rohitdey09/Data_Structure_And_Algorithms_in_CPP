// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int partition(int* arr,int start,int end){
    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=pivot)
            count++;
    }
    int pi=start+count;
    swap(arr[start],arr[pi]);
    
    int i=start,j=end;
    while(i<pi && j>pi){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pi && j>pi){
            swap(arr[i++],arr[j--]);
        }
    }
    return pi;
}

void quicksort(int* arr,int start,int end){
    if(start>=end)
        return;
    int pivot=partition(arr,start,end);
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,end);
    
}

int main() {
    int arr[]={3,6,8,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    
}