class MinStack {
public:
    
    map<int,int> dict;
    stack<int> main_stack;
    
    MinStack() {
        
    }
    
    void push(int val) {
        dict[val]++;
        main_stack.push(val);
    }
    
    void pop() {
        int it = main_stack.top();
        if(dict[it] - 1 == 0)
            dict.erase(it);
        else
            dict[it]--;
        main_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        auto it = dict.begin();
        return it->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */