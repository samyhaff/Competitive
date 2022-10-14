#include <bits/stdc++.h>
#include "linked_lists.h"

using namespace std;

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
