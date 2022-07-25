//
// Created by lindsey on 2022/4/11.
//

#include <iostream>
using namespace std;

void shellSort(int arr[], int n, int dk){
    if(n < 2){
        return;
    }
    for(int i = dk; i > 0; i=i/2){
        for(int k = i+1; k <= n; k++){
            if(arr[k] < arr[k-i]){
                arr[0] = arr[k];
                int j = k - i;
                while(j > 0 && arr[j] > arr[0] ){
                    arr[j+i] = arr[j];
                    j=j-i;
                }
                arr[j+i] = arr[0];
            }
        }
    }
}

int main(){
    int arr[8]{0,5,4,3,6,8,1,2};
    shellSort(arr,7,5);
    for(int i = 1; i<=7;i++){
        cout << arr[i];
    }
    cout << endl;
}