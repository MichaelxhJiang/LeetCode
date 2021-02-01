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
class BSTIterator {
public:
    
    stack<TreeNode*> stack;
    
    BSTIterator(TreeNode* root) {
        iterateLeft(root);
    }
    
    int next() {
        TreeNode* cur = stack.top();
        stack.pop();
        if (cur->right) {
            iterateLeft(cur->right);
        }
        
        return cur->val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
    
    void iterateLeft(TreeNode* node) {
        TreeNode* curNode = node;
        while (curNode != nullptr) {
            stack.push(curNode);
            curNode = curNode->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
