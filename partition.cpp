#include "linked_lists.h"

int main() {
    node *head = nullptr;
    head = insert(head, 7);
    head = insert(head, 6);
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    print_list(head);
    head = partition(head, 5);
    print_list(head);

    return 0;
}
