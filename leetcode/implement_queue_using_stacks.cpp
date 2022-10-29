class MyQueue {
public:
    stack<int> stack_1;
    stack<int> stack_2;

    MyQueue() {

    }

    void push(int x) {
        stack_1.push(x);
    }

    int pop() {
        while (!stack_1.empty()) {
            stack_2.push(stack_1.top());
            stack_1.pop();
        }
        int res = stack_2.top();
        stack_2.pop();
        while (!stack_2.empty()) {
            stack_1.push(stack_2.top());
            stack_2.pop();
        }
        return res;
    }

    int peek() {
        while (!stack_1.empty()) {
            stack_2.push(stack_1.top());
            stack_1.pop();
        }
        int res = stack_2.top();
        while (!stack_2.empty()) {
            stack_1.push(stack_2.top());
            stack_2.pop();
        }
        return res;
    }

    bool empty() {
        return stack_1.empty();
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
