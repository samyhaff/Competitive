#include <iostream>

#pragma once

template <typename T>
struct node {
    T val;
    node *next;
};

template <class T>
class Queue {
private:
    node<T> *head;
    node<T> *tail;
public:
    Queue() {
        head = tail = nullptr;
    }

    ~Queue() {
        node<T> *curr = head, *tmp;
        while (curr) {
            tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }

    void push(T val) {
        node<T> *new_node = new node<T>;
        new_node->val = val;
        new_node->next = nullptr;
        if (tail) tail->next = new_node;
        tail = new_node;
        if (!head) head = new_node;
    }

    void pop() {
        if (!head) std::cerr << "Queue is empty!" << std::endl;
        else {
            node<T> *tmp = head;
            head = head->next;
            if (!head) tail = nullptr;
            delete tmp;
        }
    }

    T front() {
        if (!head) std::cerr << "Queue is empty!" << std::endl;
        else return head->val;
    }

    T back() {
        if (!tail) std::cerr << "Queue is empty!" << std::endl;
        else return tail->val;
    }
};
