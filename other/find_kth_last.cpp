#include <bits/stdc++.h>
#include "linked_lists.h"

using namespace std;

int find_from_last(node *head, int k) {
    int length = get_length(head);
    return find(head, length - k - 1);
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
