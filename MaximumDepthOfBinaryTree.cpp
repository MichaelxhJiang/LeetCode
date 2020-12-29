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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return recur(root, 1);
    }
    
    int recur(TreeNode* root, int d) {
        int ans = d;
        if (root->left) {
            int left = recur(root->left, d+1);
            ans = max(ans, left);
        }
        if (root->right) {
            int right = recur(root->right, d+1);
            ans = max(ans, right);
        }
        return ans;
    }
};
