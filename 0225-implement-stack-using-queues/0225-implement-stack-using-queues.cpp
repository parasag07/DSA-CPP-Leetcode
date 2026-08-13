class MyStack {
public:
    queue<int> a;
    queue<int> b;

    void copy(queue<int>& from, queue<int>& to) {
        while (!from.empty()) {
            to.push(from.front());
            from.pop();
        }
    }

    MyStack() {
    }
    
    void push(int x) {
        if (a.empty()) {
            a.push(x);
            copy(b, a);
        } else {
            b.push(x);
            copy(a, b);
        }
    }
    
    int pop() {
        if (!a.empty()) {
            int val = a.front();
            a.pop();
            return val;
        }

        int val = b.front();
        b.pop();
        return val;
    }
    
    int top() {
        if (!a.empty()) {
            return a.front();
        }

        return b.front();
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */