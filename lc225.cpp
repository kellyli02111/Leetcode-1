class Stack {
public:
    queue<int> queues[2];
    int cur;
    Stack(){
        cur = 0;
    }
    // Push element x onto stack.
    void push(int x) {
        queues[cur].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(queues[cur].size() != 1){
            queues[1 - cur].push(queues[cur].front());
            queues[cur].pop();
        }
        queues[cur].pop();
        cur = 1 - cur;
    }

    // Get the top element.
    int top() {
        while(queues[cur].size() != 1){
            queues[1 - cur].push(queues[cur].front());
            queues[cur].pop();
        }
        int res = queues[cur].front();
        queues[1 - cur].push(queues[cur].front());
        queues[cur].pop();
        cur = 1 - cur;
        return res;
    }

    // Return whether the stack is empty.
    bool empty() {
        return queues[cur].empty();
    }
};
