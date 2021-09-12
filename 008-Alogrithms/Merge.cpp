

int *merge(int a[],int al,int b[],int bl){
    if(al == 0){
        return b;
    }
    if(bl == 0){
        return a;
    }
    int len = al+bl;
    int *arr = new int[len];
    int i=0,j=0;
    while(i < al && j < bl){
        if(a[i] < b[j]){
            arr[i+j] = a[i++];
        }else{
            arr[i+j] = b[j++];
        }
    }
    if(i < al){
        while(i < al){
            arr[i+j] = a[i++];
        }
    }
    if(j < bl){
        while(j < bl){
            arr[i+j] = b[j++];
        }
    }
    return arr;
}