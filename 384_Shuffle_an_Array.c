
typedef struct list_s {
    int val;
    struct list_s *next;
    struct list_s *prev;
}list_t;

void remove_list(list_t *node){
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

typedef struct {
    int *nums;
    int nums_mem_size;
    int *orig_nums;
} Solution;

Solution* solutionCreate(int* nums, int numsSize) {
    if(!nums || numsSize < 0){
        return NULL;
    }

    Solution *obj = calloc(1, sizeof(Solution));
    obj->nums_mem_size = sizeof(int) *numsSize;
    obj->nums = calloc(1, obj->nums_mem_size);
    obj->orig_nums = calloc(1, obj->nums_mem_size);

    memcpy(obj->nums, nums, obj->nums_mem_size);
    memcpy(obj->orig_nums, nums, obj->nums_mem_size);

    srand(time(NULL));
    return obj;
}

int* solutionReset(Solution* obj, int* retSize) {
    memcpy(obj->nums, obj->orig_nums, obj->nums_mem_size);
    *retSize = obj->nums_mem_size / sizeof(int);
    return obj->nums;
}


int* solutionShuffle(Solution* obj, int* retSize) {
    list_t *head = NULL;
    list_t *prev = NULL;
    list_t *cur = NULL;
    for(int i = 0; i < obj->nums_mem_size/sizeof(int); i++){
        cur = calloc(1, sizeof(list_t));
        cur->val = obj->nums[i];
        if(i == 0){
            head = cur;
        }else{
            prev->next = cur;
            cur->prev = prev;
        }
        prev = cur;
    }
    prev->next = head;
    head->prev = prev;

    cur = head; 
    for(int i = 0; i < obj->nums_mem_size/sizeof(int); i++){
        int r = rand() % (obj->nums_mem_size/sizeof(int) - i);
        for(int j = 0; j < r; j++){
            cur = cur->next;
        }
        obj->nums[i] = cur->val;
        list_t *tmp = cur->next;
        remove_list(cur);
        free(cur);
        cur = tmp;
    } 
    
    *retSize = obj->nums_mem_size / sizeof(int);
    return obj->nums;
}

void solutionFree(Solution* obj) {
    free(obj->nums);
    free(obj->orig_nums);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/