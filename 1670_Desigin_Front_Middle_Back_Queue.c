/*
1670. Design Front Middle Back Queue
Solved
Medium
Topics
Companies
Hint
Design a queue that supports push and pop operations in the front, middle, and back.

Implement the FrontMiddleBack class:

FrontMiddleBack() Initializes the queue.
void pushFront(int val) Adds val to the front of the queue.
void pushMiddle(int val) Adds val to the middle of the queue.
void pushBack(int val) Adds val to the back of the queue.
int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.
Notice that when there are two middle position choices, the operation is performed on the frontmost middle position choice. For example:

Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].
 

Example 1:

Input:
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
Output:
[null, null, null, null, null, 1, 3, 4, 2, -1]

Explanation:
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [1]
q.pushBack(2);    // [1, 2]
q.pushMiddle(3);  // [1, 3, 2]
q.pushMiddle(4);  // [1, 4, 3, 2]
q.popFront();     // return 1 -> [4, 3, 2]
q.popMiddle();    // return 3 -> [4, 2]
q.popMiddle();    // return 4 -> [2]
q.popBack();      // return 2 -> []
q.popFront();     // return -1 -> [] (The queue is empty)
 

Constraints:

1 <= val <= 109
At most 1000 calls will be made to pushFront, pushMiddle, pushBack, popFront, popMiddle, and popBack.
*/


//#define PRINT_QUEUE(x) print_queue(x)
#define PRINT_QUEUE(x)

typedef struct _node{
    int val;
    struct _node *prev;
    struct _node *next;
} node;

typedef struct {
    node *front;
    node *middle;
    node *back;
    int num_front;
    int num_back;
    int num_total;
} FrontMiddleBackQueue;


void print_queue(FrontMiddleBackQueue* obj) {
    if(!obj){
        return;
    }

    printf("total_num:%d front_num:%d back_num:%d front_val:%d middle_val:%d back_val:%d queue: ",
            obj->num_total,obj->num_front,obj->num_back,
            (obj->front ? obj->front->val : 0), 
            (obj->middle ? obj->middle->val : 0), 
            (obj->back ? obj->back->val : 0) 
            );
    node *n = obj->front;
    while(n){
        printf("%d ", n->val);
        n = n->next;
    }
    printf("\n");
}



FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue *obj = calloc(1, sizeof(FrontMiddleBackQueue));
    return obj;
}

node *create_new_node(int val) {
    node *n = calloc(1,sizeof(node));
    if(!n){
        return NULL;
    }
    n->val = val;
    return n;
}

void clear_queue(FrontMiddleBackQueue *obj) {
    bzero(obj, sizeof(FrontMiddleBackQueue));
}

void push_to_enpty_queue(FrontMiddleBackQueue* obj, node *n) {
    obj->front = n;
    obj->middle = n;
    obj->back = n;
    obj->num_front = 0;
    obj->num_back = 0;
    obj->num_total = 1;
}

void push_to_queue(FrontMiddleBackQueue* obj, node *n, node *target) {
    if(!obj){
        return;
    }

    if(!target){
        push_to_enpty_queue(obj, n);
        return;
    }
    
    node *tmp = target->prev;
    if(tmp){
        tmp->next = n;
    }
    n->prev = tmp;
    
    target->prev = n;
    n->next = target;
    
    (obj->num_total)++;
    return;
}

void update_middle(FrontMiddleBackQueue* obj){
    if(!obj || obj->num_total <= 0){
        return;
    }
    if(!(obj->middle)){
        return;
    }

    if(obj->num_total == 1){
        obj->middle = obj->front;
        obj->num_front = 0;
        obj->num_back = 0;
    }else if(obj->num_front > obj->num_back){
        obj->middle = obj->middle->prev;
        (obj->num_front)--;
        (obj->num_back)++;
    }else if(obj->num_front <= obj->num_back-2){
        obj->middle = obj->middle->next;
        (obj->num_front)++;
        (obj->num_back)--;
    }
    
    return;
}


void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) {
    if(!obj){
        return;
    }

    node *n = create_new_node(val);
    if(!n){
        return;
    }

    if(obj->num_total == 0){
        push_to_enpty_queue(obj, n);
    }else{
        push_to_queue(obj, n, obj->front);
        obj->front = n;
        (obj->num_front)++;

        update_middle(obj);
    }
   
    PRINT_QUEUE(obj);
    return;
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) {
    if(!obj){
        return;
    }

    node *n = create_new_node(val);
    if(!n){
        return;
    }

    if(obj->num_total == 0){
        push_to_enpty_queue(obj, n);
    }else if(obj->num_front == obj->num_back){
        push_to_queue(obj, n, obj->middle);
        if(obj->front == obj->middle){
            obj->front = n;
        }
        obj->middle = n;
        (obj->num_back)++;
    }else{
        push_to_queue(obj, n, obj->middle->next);
        obj->middle = n;
        (obj->num_front)++;
    }

    PRINT_QUEUE(obj);
    return;
    
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {
    if(!obj){
        return;
    }

    node *n = create_new_node(val);
    if(!n){
        return;
    }

    if(obj->num_total == 0){
        push_to_enpty_queue(obj, n);
    }else{
        obj->back->next = n;
        n->prev = obj->back;
        (obj->num_total)++;

        obj->back = n;
        (obj->num_back)++;
        update_middle(obj);
    }

    PRINT_QUEUE(obj);
    return;
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {
    if(!obj || !(obj->front) || obj->num_total <= 0){
        return -1;
    }

    node *n = obj->front; 
    int val = n->val;
    (obj->num_total)--;
    if(obj->num_total <= 0){
        clear_queue(obj);
    }else{
        obj->front = n->next;
        if(obj->front){
            obj->front->prev = NULL;
        }

        (obj->num_front)--;
        update_middle(obj);
    }
    free(n);
    PRINT_QUEUE(obj);
    return val;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {
    if(!obj || !(obj->middle) || obj->num_total <= 0){
        return -1;
    }

    node *n = obj->middle;
    int val = n->val;
    node *prev = n->prev;
    node *next = n->next;

    if(prev){
        prev->next = next;
    }
    if(next){
        next->prev = prev;
    }
    (obj->num_total)--;

    if(obj->num_front == obj->num_back){
        obj->middle = prev;
        if(obj->num_front > 0){
            (obj->num_front)--;
        }
    }else{
        obj->middle = next;
        if(obj->num_back > 0){
            (obj->num_back)--;
        }
    }

    if(obj->front == n){
        obj->front = obj->middle;
    }
    if(obj->back == n){
        obj->back = obj->middle;
    }

    free(n);

    PRINT_QUEUE(obj);
    return val;
    
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {
    if(!obj || !(obj->back) || obj->num_total <= 0){
        return -1;
    }

    node *n = obj->back;
    int val = n->val;
    (obj->num_total)--;
    if(obj->num_total <= 0){
        clear_queue(obj);
    }else{
        obj->back = obj->back->prev;
        if(obj->back){
            obj->back->next = NULL;
        }
        (obj->num_back)--;
        update_middle(obj);
    }
    free(n);
    PRINT_QUEUE(obj);
    return val;
    
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {
    if(!obj){
        return;
    } 

    node *n= obj->front;
    while(n){
        node *next = n->next;
        free(n);
        n = next;
    }

    free(obj);
    return;
}

/**
 * Your FrontMiddleBackQueue struct will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = frontMiddleBackQueueCreate();
 * frontMiddleBackQueuePushFront(obj, val);
 
 * frontMiddleBackQueuePushMiddle(obj, val);
 
 * frontMiddleBackQueuePushBack(obj, val);
 
 * int param_4 = frontMiddleBackQueuePopFront(obj);
 
 * int param_5 = frontMiddleBackQueuePopMiddle(obj);
 
 * int param_6 = frontMiddleBackQueuePopBack(obj);
 
 * frontMiddleBackQueueFree(obj);
*/