/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int sortint(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

typedef struct _hash_body{
    int val;
    struct _hash_body *next;
}hash_body;

typedef struct _hash_head {
    int num;
    hash_body *body;
}hash_head;

hash_head* hash_create(void){
    hash_head *head = malloc(sizeof(hash_head));
    head->num=0;
    head->hash_body = NULL;
    return head;
}

void hash_add(hash_head *head, int val){
    if (head == NULL){
        return;
    }

    hash_body node = head->next;
    while (node){
        //Todo
    }



}


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    if(nums1Size <= 0 || nums2Size <= 0){
        *returnSize = 0;
        return malloc(0);
    }

    qsort(nums1, nums1Size, sizeof(int) sortint);
    qsort(nums2, nums2Size, sizeof(int) sortint);

    int i1 = 0;
    int i2 = 0;
    while (i1 < nums1Size && i2 < nums2Size) {
        if (nums1[i1] == nums2[i2]){
            hashset_add();
            i1++;
            i2++;
        } else if(nums1[i1] < nums2[i2]){
            i1++;
        } else{
            i2++;
        }
    }


    ret = realloc(ret, sizeof(int) * ret_count);
    *returnSize = ret_count;

    return ret;
}
