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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int left = height(root->left);
        int right = height(root->right);
        if (left == right) {
            return root;
        } else if (left > right) {
            return lcaDeepestLeaves(root->left);
        } else {
            return lcaDeepestLeaves(root->right);
        }
    }
    
    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        
        return 1 + max(height(node->left), height(node->right));
    }
};
