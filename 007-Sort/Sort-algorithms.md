# Sort Algorithms

[TOC]



## Bubbles-Sort

​		

## Selection-Sort

### 1. 时间复杂度分析

​		假定一个长度为$n$待排序列$arr$为$s_1,s_2...n$，选择排序是从$arr$中挑选出一个最小的值，放到序列第一个，此时的序列为$p_1,s_1,s_2...s_{n-1}$。$p_1$为已排序完成的序列，并且是位于序列$arr$的前部，即如果排序好的项有$p_1,p_2$，则此时序列可以分为两部分，排序完成的项为$[0,2],待排序的子序列为(2,n]$，待排序的项为$n-2$个。

​		通过上述分析，可以得知，每次检索需要从$arr$的预排子序列中挑选最小值，放置到排序完成的子序列的后一个位置，即第$p$小的项放置到第$p$个位置。假设每次从待排子序列查找都需要$n-p$次，$p$即已经完成排序的项个数，则在第一次已经排序项为0时，最少需要检索$n$次，第二次在已经排序完成项为1时，检索$n-1$次，以此类推......

​		不难发现，这是一个等差数列，所以我们有如下
$$
\begin{aligned}
O(N)& =\sum_{x=1}^{n}x \\
& = \frac{n(n+1)}{2} \\
& = \frac{n^2+n}{2} \\
\end{aligned}
$$
​		根据时间复杂度定义，忽略低位，用最高项次幂作为代表的时间复杂度，可以得知：**选择排序**的时间复杂度为$O(n^2)$，并且由于每次选择第$p$小的项时，都需要尽可能遍历完毕，所以这是个稳定的排序算法，最好最差都是$O(n^2)$
### 2. 代码实现
```c++
int select_sort(int arr[],int len){

    for(int i = 0; i < len; i++){
        // the index of first item.
        int min = i;
        // find the min
        for(int j = i+1; j < len; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr,min,j);
    }
}

void swap(int arr[],int a int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
```

## Insertion-Sort

### 1.时间复杂度分析

​		待排序列$s_1,s_2,s_3...s_n$，插入排序每次会从序列头的后一个元素开始，即$s2$开始向前遍历，

## Quick-Sort

## Merger-Sort

## Shell-Sort(增强的插入排序)

## Heap-Sort(树化的选择排序)

## Bin-Sort(空间换时间)

## BaseNumber-Sort(优化桶排序)