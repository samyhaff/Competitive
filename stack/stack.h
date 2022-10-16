#pragma once

template <typename T>
struct node {
    T val;
    node *next;
};

template <class T>
class Stack {
private:
    node<T> *head;

public:
    Stack();
    ~Stack();
    T top();
    bool empty();
    unsigned int size();
    void push(T);
    void pop();
};
