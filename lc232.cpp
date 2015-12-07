//###需要改成正解
class Queue {
private:
    stack<int> st;

public:
    // Push element x to the back of queue.
    void push(int x) {
        st.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        st2.pop();
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        int res = st2.top();
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return res;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
};
