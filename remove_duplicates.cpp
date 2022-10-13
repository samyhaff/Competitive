#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    node *next;
};

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

int main() {
    node *head = NULL;
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 2);
    head = insert(head, 1);

    print_list(head);
    remove_duplicates(head);
    print_list(head);

    return 0;
}
