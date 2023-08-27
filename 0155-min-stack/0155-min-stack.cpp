class MinStack {
public:
    vector<int>st,min_st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        if(min_st.empty()){
            min_st.push_back(val);
        }else{
            min_st.push_back(min(val,min_st.back()));
        }
    }
    
    void pop() {
        min_st.pop_back();
        st.back();st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return min_st.back();
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