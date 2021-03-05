class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> inStack, outStack;
    MyQueue() {}

    void inToOut() {
        while(!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (outStack.empty()) inToOut();
        int res = outStack.top();
        outStack.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (outStack.empty()) inToOut();
        int res = outStack.top();
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (outStack.empty()) inToOut();
        return outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */