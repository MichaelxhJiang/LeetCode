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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
    
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        
        bool ans = true;
        if (p->left || q->left) ans &= check(p->left, q->left);
        if (p->right || q->right) ans &= check(p->right, q->right);
        
        return ans;
    }
};
