//
// Created by lindsey on 2021/9/9.
//


inline void swap(int arr[],int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void bubble(int arr[],int len){
    for (int i = 0; i < len; ++i){
        for (int j = i; j < len; ++j){
            if(arr[i] > arr[i+1]){
                swap(arr,i,i+1);
            }
        }
    }
}