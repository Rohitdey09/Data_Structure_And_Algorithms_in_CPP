#include<iostream>
using namespace std;

void merge(int* arr,int n,int* leftarr,int nl,int* rightarr ,int nr){
    int i=0,j=0,k=0;
    while(i<nl && j<nr){
        if(leftarr[i]<=rightarr[j]){
           arr[k]=leftarr[i];
           i++;
           k++;
        }
        else{
            arr[k]=rightarr[j];
            j++;
            k++;
        }
    }
    while(i<nl){
        arr[k]=leftarr[i];
        i++;
        k++;
    }
    while(j<nr){
        arr[k]=rightarr[j];
        j++;
        k++;
    }
}

void mergesort(int*arr,int n){
    if(n<2)
    return;
    int mid=n/2;
    int leftarr[mid];
    int rightarr[n-mid];
    for(int i=0;i<mid;i++){
        leftarr[i]=arr[i];
    }
    for(int i=mid;i<n;i++){
        rightarr[i-mid]=arr[i];
    }
    mergesort(leftarr,mid);
    mergesort(rightarr,n-mid);
    merge(arr,n,leftarr,mid,rightarr,n-mid);

}


int main()
{
    int arr[]={4,6,8,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

 return 0;
}