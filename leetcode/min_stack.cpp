struct Node {
    int val;
    int min;
    Node *next;
};

class MinStack {
private:
    Node *head;
public:
    MinStack() {
        head = nullptr;
    }

    void push(int val) {
        Node *new_head = new Node;
        new_head->val = val;
        if (head)
            new_head->min = min(val, head->min);
        else
            new_head->min = val;
        new_head->next = head;
        head = new_head;
    }

    void pop() {
        head = head->next;
    }

    int top() {
       return head->val;
    }

    int getMin() {
       return head->min;
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
