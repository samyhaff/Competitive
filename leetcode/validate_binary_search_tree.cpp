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
    bool aux(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (!root) return true;
        return ((!max || root->val < max->val) && (!min || root->val > min->val) && aux(root->right, root, max) && aux(root->left, min, root));
    }

    bool isValidBST(TreeNode* root) {
        return aux(root, nullptr, nullptr);
    }
};
