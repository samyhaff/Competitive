#include <iostream>
#include "stack.h"
#include "stack.cpp"

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.top() << std::endl;
    stack.pop();
    std::cout << stack.top() << std::endl;
    std::cout << stack.size() << std::endl;
    std::cout << stack.empty() << std::endl;
}
