/*
641. Design Circular Deque
Solved
Medium
Topics
Companies
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
*/




typedef struct {
    int *buf;
    unsigned int front;
    unsigned int rear;
    int capacity;
    int size;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *obj = calloc(1, sizeof(MyCircularDeque));
    if(!obj){
        return NULL;
    }

    obj->buf = calloc(k,sizeof(int));
    if(!(obj->buf)){
        free(obj);
        return NULL;
    }

    obj->front = k-1;
    obj->capacity = k;

    return obj;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return (obj->size == 0); 
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return (obj->size != 0 && obj->size % obj->capacity == 0); 
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(!obj){
        return false;
    }

    if(myCircularDequeIsFull(obj)){
        return false;
    }

    obj->buf[obj->front % obj->capacity] = value;
    obj->front = obj->front + obj->capacity - 1;
    (obj->size)++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(!obj){
        return false;
    }

    if(myCircularDequeIsFull(obj)){
        return false;
    }

    obj->buf[obj->rear % obj->capacity] = value;
    (obj->rear)++;
    (obj->size)++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(!obj){
        return false;
    }

    if(myCircularDequeIsEmpty(obj)){
        return false;
    }

    (obj->front)++;
    (obj->size)--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(!obj){
        return false;
    }

    if(myCircularDequeIsEmpty(obj)){
        return false;
    }

    obj->rear= obj->rear + obj->capacity - 1;
    (obj->size)--;
    return true;
    
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(!obj){
        return -1;
    }

    if(myCircularDequeIsEmpty(obj)){
        return -1;
    }
    return obj->buf[(obj->front + 1) % obj->capacity];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(!obj){
        return -1;
    }

    if(myCircularDequeIsEmpty(obj)){
        return -1;
    }
    return obj->buf[(obj->rear + obj->capacity - 1) % obj->capacity];
}


void myCircularDequeFree(MyCircularDeque* obj) {
    if(!obj || !obj->buf){
        return;
    }
    free(obj->buf);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
