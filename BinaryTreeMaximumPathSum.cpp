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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        getMaxPath(root, maxSum);
        return maxSum;
    }
    
    int getMaxPath(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        
        int curPathSum = node->val;
        int newPathSum = node->val;
        int left = max(0, getMaxPath(node->left, maxSum));
        int right = max(0, getMaxPath(node->right, maxSum));
        curPathSum = max(curPathSum + left, curPathSum + right);
        newPathSum += left + right;
        
        if (newPathSum > maxSum) maxSum = newPathSum;
        
        return curPathSum;
    }
};
