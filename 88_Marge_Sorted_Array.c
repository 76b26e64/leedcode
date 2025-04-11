void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if(!nums1 || !nums2 || nums1Size <= 0 || m < 0 || nums2Size <= 0 || n < 0){
        return;
    }

    int target_index = m + n - 1;
    m--;
    n--;
    while(n>=0){
        if(m >= 0 && nums1[m] >= nums2[n]){
            nums1[target_index--] = nums1[m--];
        }else{
            nums1[target_index--] = nums2[n--];
        }
    } 
}
