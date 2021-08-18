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
    int kthSmallest(TreeNode* root, int k) {
        // recurse in-order to get list of ascending elements
        // return kth element
        
        /*
        Note: for iterative solution: 
        Use a stack and continue adding left child nodes before moving one over to the right
        
        stack<TreeNode*> stack;
        
        while (true) {
            // push all left children
            while (root != null) {
                stack.push_back(root);
                root = root->left;
            }
            
            // check child nodes bottom-up (ascending order) (with stack's natural order)
            root = stack.pop_back();
            if (--k == 0) return root->val;
            
            // try moving to the right (nodes larger than root but smaller than 
            // next node in the stack)
            root = root->right;
        }
        */
        vector<int> inOrder = inOrderBST(root);
        
        return inOrder[k-1];
    }
    
    vector<int> inOrderBST(TreeNode* node) {
        vector<int> inOrder;
        vector<int> res;
        if (node->left) {
            res = inOrderBST(node->left);
            inOrder.insert(inOrder.end(), res.begin(), res.end());
        }
        inOrder.push_back(node->val);
        if (node->right) {
            res = inOrderBST(node->right);
            inOrder.insert(inOrder.end(), res.begin(), res.end());
        }
        return inOrder;
    }
};
