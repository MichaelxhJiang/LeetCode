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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int ans = 0;
        maxLength(root, ans);
        
        return ans-1;
    }
    
    int maxLength(TreeNode* node, int& ans) {
        if (node == nullptr) return 0;
        
        int left = 0;
        int right = 0;
        if (node->left) {
            left = maxLength(node->left, ans);
        }
        if (node->right) {
            right = maxLength(node->right, ans);
        }
        
        int maxPath = left + right + 1;
        if (maxPath > ans) ans = maxPath;
        
        return 1 + max(left, right);
    }
};
