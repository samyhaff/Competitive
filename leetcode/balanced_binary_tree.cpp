/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    bool isBalanced(TreeNode* root) {
       if (!root) return true;
       int left_height = getHeight(root->left);
       int right_height = getHeight(root->right);
       return (max(right_height, left_height) - min(right_height, left_height) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
};
