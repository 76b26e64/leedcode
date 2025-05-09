/*
622. Design Circular Queue
Solved
Medium
Topics
Companies
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language. 

 

Example 1:

Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.
*/




typedef struct {
    int *buf;
    int size;
    unsigned int front;
    unsigned int rear;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj = calloc(1, sizeof(MyCircularQueue));
    if(!obj){
        return NULL;
    }
    obj->buf = calloc(k, sizeof(int));
    obj->capacity = k;

    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(!obj || obj->size == obj->capacity){
        return false;
    }

    obj->buf[obj->rear++] = value;
    obj->rear %= obj->capacity;
    (obj->size)++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(!obj || obj->size == 0){
        return false;
    }
    
    obj->front++;
    obj->front %= obj->capacity;
    (obj->size)--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(!obj || obj->size == 0){
        return -1;
    }
    int index = obj->front % obj->capacity;
    return obj->buf[index];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(!obj || obj->size == 0){
        return -1;
    }
    int index = (obj->capacity + obj->rear - 1) % obj->capacity;
    return obj->buf[index];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj && obj->size == 0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj && obj->size == obj->capacity);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(!obj){
        return;
    }

    if(obj->buf){
        free(obj->buf);
    }
    free(obj);
    return;
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