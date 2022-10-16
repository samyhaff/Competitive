#include <iostream>
#include "stack.h"

using namespace std;

template <class T>
Stack<T>::Stack() {
    head = nullptr;
}

template <class T>
Stack<T>::~Stack() {
    node<T> *curr = head, *tmp;
    while (curr) {
        tmp = curr->next;
        delete curr;
        curr = tmp;
    }
}

template <class T>
T Stack<T>::top() {
    if (!head) cerr << "Stack is empty!" << endl;
    else return head->val;
}

template <class T>
bool Stack<T>::empty() {
    return (!head);
}

template <class T>
unsigned int Stack<T>::size() {
    int size = 0;
    node<T> *curr = head;
    while (curr) {
        size++;
        curr = curr->next;
    }
    return size;
}

template <class T>
void Stack<T>::push(T val) {
    node<T> *new_head = new node<T>;
    new_head->val = val;
    new_head->next = head;
    head = new_head;
}

template <class T>
void Stack<T>::pop() {
    node<T> *tmp;
    if (!head) cerr << "Stack is empty!" << endl;
    tmp = head;
    head = head->next;
    delete tmp;
}
