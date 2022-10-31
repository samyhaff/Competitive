class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> stack;
        long x, y;

        for (string token: tokens) {
            if (token == "+") {
                x = stack.top(); stack.pop();
                y = stack.top(); stack.pop();
                stack.push(x + y);
            } else if (token == "-") {
                x = stack.top(); stack.pop();
                y = stack.top(); stack.pop();
                stack.push(y - x);
            } else if (token == "*") {
                x = stack.top(); stack.pop();
                y = stack.top(); stack.pop();
                stack.push(x * y);
            } else if (token == "/") {
                x = stack.top(); stack.pop();
                y = stack.top(); stack.pop();
                stack.push(y / x);
            } else stack.push(stoi(token));
        }
        return stack.top();
    }
};
