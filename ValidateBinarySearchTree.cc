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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        
        return dfs(root, NULL, NULL, true, true);
    }
    
    bool dfs(TreeNode* root, int upper, int lower, bool upper_null, bool lower_null) {
        if (!upper_null && root->val >= upper) return false;
        if (!lower_null && root->val <= lower) return false;
        
        bool ans = true;
        
        if (root->left != nullptr) {
            int newUpper = upper_null ? root->val : min(root->val, upper); 
            ans &= dfs(root->left, newUpper, lower, false, lower_null);
        }
        
        if (root->right != nullptr) {
            int newLower = lower_null ? root->val : max(root->val, lower);
            ans &= dfs(root->right, upper, newLower, upper_null, false);
        }
        
        return ans;
    }
};
