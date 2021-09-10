

inline void swap(int arr[],int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void insertion_sort(int arr[],int len){
    if(len < 1){
        return;
    }
    for (int i = 1; i < len; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            swap(arr,j,j+1);
            j--;
        }
        arr[j+1] = temp;
    }
    
}

