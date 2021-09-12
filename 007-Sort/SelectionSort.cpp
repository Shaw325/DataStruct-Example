//
// Created by lindsey on 2021/9/7.
//
#include "swap.h"


void selection_sort(int arr[],int len){
    for(int i=0; i < len; i++){
        int min = i;
        for(int j=i+1;j < len; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}