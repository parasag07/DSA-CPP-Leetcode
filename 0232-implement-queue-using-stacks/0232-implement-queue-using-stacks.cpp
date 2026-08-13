class MyQueue {
public:
    stack<int> a;
    stack<int> b;

    void copy(stack<int>& a, stack<int>& b){
        while( !a.empty() ){
            b.push(a.top());
            a.pop();
        }
    }

    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        if(b.empty()){
            copy(a, b);
        }
        int val = b.top();
        b.pop();
        return val;
    }
    
    int peek() {
        if(b.empty()){
            copy(a, b);
        }
        return b.top();
    }
    
    bool empty() {
        return a.empty() && b.empty();
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