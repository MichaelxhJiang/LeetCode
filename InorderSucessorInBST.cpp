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
    // in order successor is the parent of the first left branch (from parent's perspective)
    // above node p
    // OR is the right branch's leftmost child
    
    // BST property: if p is greater than current node, discord current node's left tree completely
    // since all nodes in left tree are smaller than p. So we go to right subtree
    // else, successor is either current node or in the left subtree. Save current node, go to 
    // left subtree to continue search
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* cur = root;
        TreeNode* ans = nullptr;        
        while (cur != nullptr) {
            if (p->val >= cur->val) {
                // successor is in right subtree
                cur = cur->right;
            } else {
                // current node is a successor, potentially the in-order successor
                ans = cur;
                cur = cur->left;
            }
        }
        
        return ans;
    }
};
