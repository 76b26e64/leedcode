#include <stdio.h>
#include <string.h>

// To execute C, please define "int main()"
void mergesort(int *array, int *helper, int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        mergesort(array, helper, low, mid);
        mergesort(array, helper, mid+1, high);
        merge(array, helper, low, mid, high);
    }

}

void merge(int *array, int *helper, int low, int mid, int high){

    memcpy(&(helper[low]), &(array[low]), sizeof(int) * (high-low+1));

    int helper_left = low;
    int helper_right = mid+1;
    int cur = low;

    while(helper_left <= mid && helper_right <= high){
        if(helper[helper_left] <= helper[helper_right]){
            array[cur++] = helper[helper_left++];
        }else {
            array[cur++] = helper[helper_right++];
        }
    }

    int  remain = mid - helper_left;
    for (int i = 0; i <= remain; i++){
        array[cur+i] = helper[helper_left+i];
    }
}


int main() {
    int a[10] = {8,4,7,2,1,3,5,6,-1,9};
    int b[10] = {0};
    const int n = 10;
    int i;
    mergesort(a, b, 0, n-1);
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
