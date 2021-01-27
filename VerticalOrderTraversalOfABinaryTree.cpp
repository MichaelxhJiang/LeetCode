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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> reports; // x -> (y -> set of nodes)
        
        queue<pair<TreeNode*, pair<int, int>>> queue;
        queue.push({root, {0, 0}});
        
        while (!queue.empty()) {
            pair<TreeNode*, pair<int, int>> node = queue.front();
            queue.pop();
            int x = node.second.first;
            int y = node.second.second;
            TreeNode* n = node.first;
            
            
            if (reports.find(x) == reports.end()) {
                reports.insert({x, map<int, set<int>>()});
            }
            if (reports[x].find(y) == reports[x].end()) {
                reports[x].insert({y, set<int>()});
            }
            reports[x][y].insert(n->val);
            
            if (n->left) {
                queue.push({n->left, {x-1, y+1}});
            }
            if (n->right) {
                queue.push({n->right, {x+1, y+1}});
            }
        }
        
        vector<vector<int>> ans;
        int index = 0;
        for (auto xData : reports) {
            ans.push_back(vector<int>());
            for (auto yData : xData.second) {
                for (int node : yData.second) {
                    ans[index].push_back(node);
                }
            }
            index++;
        }
        
        return ans;
    }
};
