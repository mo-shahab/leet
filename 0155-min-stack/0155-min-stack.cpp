class MinStack {
public:
    stack<int> data;
    stack<int> minStack;

    MinStack() {}
    
    void push(int val) {
        if(minStack.empty() || minStack.top() >= val){
            minStack.push(val);
        }
        data.push(val);
    }
    
    void pop() {
        if(minStack.top() == data.top()){
            minStack.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your minStackStack object will be instantiated and called as such:
 * minStackStack* obj = new minStackStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getmink();
 */