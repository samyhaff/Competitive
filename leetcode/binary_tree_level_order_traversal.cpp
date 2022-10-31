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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        queue<TreeNode *> queue;
        TreeNode *current;
        int length;

        if (!root) return traversal;
        queue.push(root);

        while (!queue.empty()) {
            length = queue.size();
            vector<int> level;
            for (int i = 0; i < length; i++) {
                current = queue.front(); queue.pop();
                level.push_back(current->val);
                if (current) {
                    if (current->left) queue.push(current->left);
                    if (current->right) queue.push(current->right);
                }
            }
            traversal.push_back(level);
        }

        return traversal;
    }
};
