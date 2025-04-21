/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

#define MAX_STACK_NUM (30000)

typedef struct {
    int *stack;
    int stack_top;
    int *min_stack;
    int min_stack_top;
    int min_val;
} MinStack;


MinStack* minStackCreate() {
    MinStack* obj = calloc(1, sizeof(MinStack));  
    obj->stack = calloc(MAX_STACK_NUM, sizeof(int));  
    obj->min_stack = calloc(MAX_STACK_NUM, sizeof(int));  
    obj->min_val = INT_MAX;  
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if(obj->stack_top >= MAX_STACK_NUM){
        return;
    }
    obj->stack[obj->stack_top++] = val;
    if(val <= obj->min_val){
        obj->min_stack[obj->min_stack_top++] = val;
        obj->min_val = val;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->stack_top <= 0){
        return;
    }
    if(obj->stack[obj->stack_top-1] == obj->min_val){
        obj->min_stack_top--;
        if(obj->min_stack_top <= 0){
            obj->min_val = INT_MAX;
        }else{
            obj->min_val = obj->min_stack[obj->min_stack_top-1];
        }
    }
    obj->stack_top--;
}

int minStackTop(MinStack* obj) {
    if(obj->stack_top <= 0){
        return 0;
    }
    return obj->stack[obj->stack_top-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min_val;
}

void minStackFree(MinStack* obj) {
    if(!obj || !(obj->stack) || !(obj->min_stack)){
        return;
    }
    free(obj->stack);  
    free(obj->min_stack);  
    free(obj);  
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

