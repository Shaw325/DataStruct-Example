//
// Created by lindsey on 2021/9/9.
//
#include "swap.h"


void bubble(int arr[],int len){
    bool flag = true;
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len-1; ++j){
            if(arr[j] > arr[j+1]){
                sort_swap(arr,j,j+1);
                flag = false;
            }
        }
        if(flag){
            break;
        }
    }
}