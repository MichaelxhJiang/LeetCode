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
    TreeNode* recurse(TreeNode* node) {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
            return node;
        }
        
        //Invert left and right child
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        recurse(node->left);
        recurse(node->right);
        
        return node;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return recurse(root);
    }
};
