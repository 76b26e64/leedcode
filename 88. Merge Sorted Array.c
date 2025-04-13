void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    int answer_size = m+n;
    int *tmp = malloc(sizeof(int) * answer_size);
    memcpy(tmp, nums1, sizeof(int) * answer_size);

    int tmp_index = 0;
    int num1_index = 0;
    int num2_index = 0;
    while (tmp_index+num2_index <= m+n){
        if (tmp_index < m && num2_index < n){
            if(tmp[tmp_index] < nums2[num2_index]){
                nums1[num1_index++] = tmp[tmp_index++];
            }else{
                nums1[num1_index++] = nums2[num2_index++];
            }
        }else if(tmp_index < m){
            memcpy(&nums1[num1_index], &tmp[tmp_index], sizeof(int)*(m-tmp_index));
            break; 
        }else{
            memcpy(&nums1[num1_index], &nums2[num2_index],  sizeof(int)*(n-num2_index));
            break; 
        }
    }

    free(tmp);
    return;
}