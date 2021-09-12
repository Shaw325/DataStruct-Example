

void m(int arr[],int al,int ar,int bl,int br){
    int alen = ar - al + 1;
    int blen = br - bl + 1;
    if(alen == 0 || blen == 0){
        return;
    }
    int temp[alen+blen];
    int i=al,j=bl;
    int idx = 0;
    while(i <= ar && j <= br){
        if(arr[i] < arr[j]){
            temp[idx++]=arr[i++];
        }else{
            temp[idx++]=arr[j++];
        }
    }
    while(i <= ar) temp[idx++]=arr[i++];
    while(j <= br) temp[idx++]=arr[j++];
    for(int k = 0; k < alen+blen;k++){
        arr[al++] = temp[k];
    }
}

void r(int arr[],int left,int right){
    if(left >= right){
        return;
    }
    int k = (left+right)/2;
    r(arr,left,k);
    r(arr,k+1,right);
    m(arr,left,k,k+1,right);
}


void merge_sort(int arr[],int len){
    r(arr,0,len-1);
}



