class Solution {
public:
    struct Node {
        int value;
        int leftSize;   // store size of left subtree plus itself
        Node *left;
        Node *right;   
    };
    Node *root = new Node();
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return vector<int>();
        
        vector<int> ans(nums.size());
        root->value = nums[nums.size()-1];
        root->leftSize = 1;
        root->left = nullptr;
        root->right = nullptr;
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            insertAndGetAns(root, nums[i], ans[i]);
        }
        
        return ans;
    }
    
    Node* insertAndGetAns(struct Node* node, int value, int& ans) {
        if (node == nullptr) {
            Node* newNode = new Node();
            newNode->value = value;
            newNode->leftSize = 1;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }
        if (value <= node->value) {
            node->left = insertAndGetAns(node->left, value, ans);
            node->leftSize++;
        } else {
            ans += node->leftSize;
            node->right = insertAndGetAns(node->right, value, ans);
        }
        
        return node;
    }
};
