class MinStack {
public:
    stack<int> st;
    stack<int> st_min;
    void push(int x) {
        st.push(x);
        if(st_min.empty()){
            st_min.push(x);
            return;
        }
        if(st_min.top() >= x){
            st_min.push(x);
            return;
        }
        
    }

    void pop() {
        if(st_min.top() == st.top()){
            st_min.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return st_min.top();
    }
};
