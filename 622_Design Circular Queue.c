typedef struct {
    int *buf;
    int size;
    int head;
    int tail;
    int capacity;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj = calloc(1, sizeof(MyCircularQueue));
    obj->buf = calloc(k, sizeof(int));
    obj->capacity = k;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->size == 0); 
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->size == obj->capacity); 
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->buf[(obj->tail)%(obj->capacity)];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->buf[((obj->head)-1+obj->capacity)%(obj->capacity)];
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(!obj || myCircularQueueIsFull(obj)){
        return false;
    }
    obj->buf[obj->head] = value;
    obj->head = (obj->head+1)%(obj->capacity);
    obj->size++;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(!obj || myCircularQueueIsEmpty(obj)){
        return false;
    }
    obj->tail = (obj->tail+1)%(obj->capacity);
    obj->size--;
    return true;
    
}


void myCircularQueueFree(MyCircularQueue* obj) {
    if(!obj || !(obj->buf)){
        return;
    }
    free(obj->buf);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
