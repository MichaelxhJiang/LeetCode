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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        
        vector<int> ans;
        
        int layer = 0;
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 1});
        
        while (!queue.empty()) {
            pair<TreeNode*, int> node = queue.front();
            queue.pop();
            
            // check if we are on new layer
            if (layer != node.second) {
                ans.push_back(node.first->val);
                layer++;
            }
            
            // right to left
            if (node.first->right) {
                queue.push({node.first->right, node.second+1});
            }
            if (node.first->left) {
                queue.push({node.first->left, node.second+1});
            }
        }
        
        return ans;
    }
};
