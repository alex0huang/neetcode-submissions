class MinStack {
public:
    stack<int>sk;
    stack<int>mins;
    MinStack() {}
    
    void push(int val) {
        sk.push(val);
        val = min(val,mins.empty() ? val:mins.top());
        mins.push(val);

    }
    
    void pop() {
        sk.pop();
        mins.pop();
    }
    
    int top() {
       return sk.top();

    }
    
    int getMin() {
        return mins.top();
    }
};
