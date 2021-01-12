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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca;
        dfs(root, p, q, &lca);
        return lca;
    }
    
    pair<bool, bool> dfs(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode** lca) {
        if (node == nullptr) {
            return {false, false};
        }
        pair<bool, bool> found = {false, false};
        if (node->val == p->val) {
            found.first = true;
        } else if (node->val == q->val) {
            found.second =true;
        }
        
        pair<bool, bool> left = dfs(node->left, p, q, lca);
        found.first |= left.first;
        found.second |= left.second;
        
        pair<bool, bool> right = dfs(node->right, p, q, lca);
        found.first |= right.first;
        found.second |= right.second;
        
        if (left.first && left.second) return found;    // already found lca
        if (right.first && right.second) return found;  // already found lca
        if (found.first && found.second) {  //update lca
            *lca = node;
        }
        return found;
    }
};
