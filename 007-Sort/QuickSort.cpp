
#include "swap.h"


void quick(int arr[],int left,int right){
    if(left >= right){
        return;
    }
    int mark = arr[left];
    int i=left,j=right;
    while(i < j){
        // 从右往左找一个比基准值小的值
        while(i < j && arr[j] > mark){
            j--;
        }
        // 从左往右找一个比基准值大的值
        while(i < j && arr[i] < mark){
            i++;
        }
        // 交换两个值
        sort_swap(arr,i,j);
    }
    // 把左边的再次执行
    quick(arr,left,i);
    // 把右边的再次执行
    quick(arr,i+1,right);
}

/**
 * arr: {5,7,8,9,1,3}
 * arr: {3,7,8,9,1,5}
 * arr: {3,5,8,9,1,7}
 * arr: {3,1,8,9,5,7}
 * arr: {3,1,5,9,8,7}
 * arr: {3,1,5,9,8,7}
 */
void quick_sort(int arr[],int len){
    quick(arr,0,len-1);
}
