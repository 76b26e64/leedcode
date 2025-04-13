#include <stdio.h>
#include <string.h>

// To execute C, please define "int main()"
void quicksort(int *array, int left, int right){
    int index = partition(array, left, right);
    if (left < index-1){
        quicksort(array, left, index-1);
    }
    if (index< right) {
        quicksort(array, index, right);
    }
}

int partition(int *array, int left, int right){
    int pivot = array[(left+right)/2];
    while(left<=right){
        while(array[left] < pivot){
            left++;
        }
        while(pivot < array[right]){
            right--;
        }

        if(left <= right){
            int tmp = array[left];
            array[left] = array[right];
            array[right] = tmp;
            left++;
            right--;
        }
    }

    return left;
}



int main() {
    int a[10] = {8,4,7,2,1,3,5,6,-1,0};
    int b[10] = {0};
    const int n = 10;
    int i;
    quicksort(a, 0, n-1);
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
