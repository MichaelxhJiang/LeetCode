/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        
        string serial = "";
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node == nullptr) {
                serial += "#,";
            } else {
                serial += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        vector<int> sequence = extractStrings(data);
        
        TreeNode* root = new TreeNode(sequence[0]);
        queue<TreeNode*> q; // only push non-null nodes into queue
        q.push(root);
        int index = 1;  // iterate over every single string in sequence
        
        while (!q.empty() && index < sequence.size()) {
            TreeNode* node = q.front();
            q.pop();
            if (sequence[index] != 1001) {
                TreeNode* left = new TreeNode(sequence[index]);
                node->left = left;
                q.push(left);
            }
            index++;
            if (sequence[index] != 1001) {
                TreeNode* right = new TreeNode(sequence[index]);
                node->right = right;
                q.push(right);
            }
            index++;
        }
        
        return root;
    }
    
    vector<int> extractStrings(string data) {
        vector<int> sequence;
        int curAns = 0;
        int index = 0;
        int sign = 1;
        while (index < data.size()) {
            if (data[index] == ',') {
                sequence.push_back(curAns*sign);
                curAns = 0;
                sign = 1;
            } else if (data[index] == '#') {
                sequence.push_back(1001);
                index++;
            } else if (data[index] == '-') {
                sign = -1;
            } else {
                curAns = curAns*10 + (data[index] - '0');
            }
            index++;
        }
                                  
        return sequence;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
