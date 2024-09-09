#include <stdio.h>
int arr[5] = {5,2,3,1,4};

void merge(int left, int mid, int right){
    int temp[5];
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i];
            i++;
        }else{
            temp[k++] = arr[j];    
            j++;
        }
    }
    if(i <= mid){
        while(i <= mid){
            temp[k++] = arr[i];
            i++;
        }
    }
    if(j <= right){
        while(j <= right){
            temp[k++] = arr[j];
            j++;
        }
    }
    for(int i = left; i <= right; i++){
        arr[i] = temp[i];
    }
}

void merge_sort(int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        merge_sort(left,mid);
        merge_sort(mid+1, right);
        merge(left, mid, right);
    }
}

int main(){
    int left = 0, right = 4;
    merge_sort(left, right);
    printf("output : ");
    for(int i = left; i <= right; i++){
        printf("%d, ", arr[i]);
    }
}