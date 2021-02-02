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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return 0;
        
        return inOrder(root, low, high);
    }
    
    int inOrder(TreeNode* node, int low, int high) {
        int ans = 0;
        if (node->left) {
            ans += inOrder(node->left, low, high);
        }
        
        // exit if node is larger than high
        if (node->val > high) return ans;
        
        if (node->val >= low && node->val <= high) {
            ans += node->val;
        }
        
        if (node->right) {
            ans += inOrder(node->right, low, high);
        }
        
        return ans;
    }
};
