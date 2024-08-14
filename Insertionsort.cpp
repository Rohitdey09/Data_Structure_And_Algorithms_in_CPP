#include<iostream>
using namespace std;

int insertionsort(int* arr,int n){
    for (int i = 1; i < n; i++) {
        int j = i-1;
        int current = arr[i];
        for (; j > 0  ; j--)
        {
            if (arr[j]>current)
            {
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            
        }
       arr[j+1]=current; 
    }
    return 0;
}

int main()
{   
    int arr[8] = {1,2,5,3,6,8,7,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,n);
    cout << "The sorted array is ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
 return 0;
}

