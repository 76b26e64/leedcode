/*
 * Problem: 232. Implement Queue using Stacks
 * Link: https://leetcode.com/problems/implement-queue-using-stacks/description/
 * Difficulty: Easy
 * Approach: Using input output stack.
 * Complexity: Time : O(1), Space : O(n)
 * Edge cases: pop/peak when stack is empty.
*/


class MyQueue {

private:
    std::stack<int> input_;
    std::stack<int> output_;

    void output_update() {
        if(!output_.empty()){
            return;
        }
        
        while(!input_.empty()){
            output_.push(input_.top()); 
            input_.pop(); 
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        input_.push(x);
    }
    
    int pop() {
        if(empty()){
            throw std::underflow_error(std::format("{}:Queue is empty", __func__)); 
        }
    
        output_update();
        int ret = output_.top(); 
        output_.pop(); 
        return ret;
    }
    
    int peek() {
        if(empty()){
            throw std::underflow_error(std::format("{}:Queue is empty", __func__)); 
        }
       
        output_update();
        return output_.top(); 
    }
    
    bool empty() {
        return input_.empty() && output_.empty();
    }
};
