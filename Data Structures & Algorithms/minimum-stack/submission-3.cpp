class MinStack {
private:
    stack<int> pila;
    stack<int> ordered {{INT_MAX}};
public:
    MinStack() {
    }
    
    void push(int val) {
        if (val <= ordered.top()) {
            ordered.push(val);
        }
        pila.push(val);
    }
    
    void pop() {
        if (pila.empty()) return;
        int val = pila.top();
        if (val == ordered.top()) {
            ordered.pop();
        }
        pila.pop();
    }
    
    int top() {
        return pila.top();
    }
    
    int getMin() {
        return ordered.top();
    }
};
