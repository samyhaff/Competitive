/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *aux(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root->val > p->val && root->val < q->val) return root;
        if (root->val == p->val || root->val == q->val) return root;
        if (p->val <= root->val && q->val <= root->val) return aux(root->left, p, q);
        return aux(root->right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < q->val) return aux(root, p, q);
        else return aux(root, q, p);
    }
};
