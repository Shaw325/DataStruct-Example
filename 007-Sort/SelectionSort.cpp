//
// Created by lindsey on 2021/9/7.
//
#include "swap.h"

#include <iostream>

using namespace std;

void swap(int arr[],int a,int b);

void selection_sort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

/**
 * 双路选择排序
 * @param arr
 * @param len
 */
void d_selection_sort(int arr[], int len) {
    for (int i = 0; i < len / 2; i++) {
        int min = i;
        int max = i;
        for (int j = i + 1; j < len - i; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        if (min == max) {
            continue;
        }
        /**
         * 1. 最小值在最大值要放置的位置
         *
         * 2. 最大值在最小值要放置的位置
         * 3. 最大值和最小值分别在对方要放置的位置
         */
        swap(arr,max,len-i-1);
        if(min == len-i-1){
            swap(arr,max,i);
        }else{
            swap(arr,min,i);
        }
    }
}

void swap(int arr[],int a,int b){
    if(a != b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}


int main() {
    int arr[5] = {9, 1, 5, 0, 3};
    d_selection_sort(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}