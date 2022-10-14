#include <iostream>
#include <unordered_set>
#include "linked_lists.h"

using namespace std;

node *remove_duplicates(node *head) {
    node *current = head, *tmp;
    unordered_set<int> values;

    while (current->next) {
        if (values.find(current->next->val) == values.end())
            values.insert(current->next->val);
        else {
            tmp = current->next->next;
            delete current->next;
            current->next = tmp;
        }
        current = current->next;
    }

    return head;
}

void print_list(node *head) {
    node *current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

node *insert(node *head, int val) {
    node *new_head = new node;
    new_head->next = head;
    new_head->val = val;
    return new_head;
}

int get_length(node *head) {
    int length = 0;
    node *current = head;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

int find(node *head, int k) {
    node *current = head;
    int idx = 0;
    while (idx++ < k) current = current->next;
    return current->val;
}
