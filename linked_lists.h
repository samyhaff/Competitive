#pragma once

struct node {
    int val;
    node *next;
};

void print_list(node *);
node *insert(node *, int);
node *remove_duplicates(node *);
int get_length(node *);
int find(node *, int);
int get_max(node *);
node *partition(node *, int);
