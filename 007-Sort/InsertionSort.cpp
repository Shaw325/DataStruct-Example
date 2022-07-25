#include "swap.h"
#include <iostream>
using namespace std;

void insertion_sort(int arr[],int len){
    if(len < 1){
        return;
    }
    for (int i = 1; i < len; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            sort_swap(arr,j,j+1);
            j--;
        }
        arr[j+1] = temp;
    }
}


void insertionSort(int arr[],int n){
    if(n <= 1){
        return;
    }
    for(int i = 2; i <= n; i++){
        arr[0] = arr[i];
        int j = i - 1;
        while(j >= 1 && arr[j] > arr[0]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = arr[0];
    }
}

int main(){
    int arr[7]{0,4,3,6,8,1,2};
    insertionSort(arr,6);
    for(int i = 1; i<=6;i++){
        cout << arr[i];
    }
    cout << endl;
}