#include <iostream>

using namespace std;

struct tree {
    int val;
    tree *left;
    tree *right;
};

tree *invert(tree *root) {
    if (!root) return nullptr;
    tree *left = invert(root->left);
    tree *right = invert(root->right);
    root->right = left;
    root->left = right;
    return root;
}

tree *create(int val, tree *left, tree *right) {
    tree *root = new tree;
    root->val = val;
    root->left = left;
    root->right = right;
    return root;
}

void print(tree *root, int depth) {
    if (!root) cout << string(depth, '-') << "NULL" << endl;
    else {
    cout << string(depth, '-') << root->val << endl;
    print(root->left, depth + 1);
    print(root->right, depth + 1);
    }
}

int main() {
    tree root = {
        .val = 0,
        .left = create(1, create(2, nullptr, nullptr), create(3, nullptr, nullptr)),
        .right = create(4, create(5, nullptr, nullptr), create(6, nullptr, nullptr))
    };

    print(&root, 0);
    invert(&root);
    print(&root, 0);

    return 0;
}
