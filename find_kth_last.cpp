#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *next;
};

int get_length(node *head) {
    int length = 0;
    node *current = head;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}

int find_element(node *head, int k) {
    node *current = head;
    int idx = 0;
    while (idx++ < k) current = current->next;
    return current->val;
}

int find_from_last(node *head, int k) {
    int length = get_length(head);
    return find_element(head, length - k - 1);
}

node *insert(node *head, int val) {
    node *new_head = new node;
    new_head->next = head;
    new_head->val = val;
    return new_head;
}

int main() {
    node *head = NULL;
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    cout << find_from_last(head, 0) << endl;

    return 0;
}
