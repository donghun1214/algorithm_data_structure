#include <stdio.h>
int arr[5] = {5,2,3,1,4};

void merge(int left, int mid, int right){
    //임시 배열을 생성해서 두 배열을 담기.
    int temp[5], temp2[5];
    for(int i = left; i <= mid; i++){
        temp[i] = arr[i];
    }
    for(int i = mid + 1; i <= right; i++){
        temp2[i] = arr[i];
    }


    //두 배열 비교해서 arr 갱신하기.
    int start_temp1 = left, start_temp2 = mid + 1;
    int start = left;
    while(start <= right){
        if(start_temp1 <= mid && (start_temp2 > right || temp[start_temp1] <= temp2[start_temp2])){
            arr[start] = temp[start_temp1];
            start_temp1++;
        } else if(start_temp2 <= right && start_temp1 > mid || temp[start_temp1] > temp2[start_temp2]){
            arr[start] = temp2[start_temp2];
            start_temp2++;
        }
        start++;
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