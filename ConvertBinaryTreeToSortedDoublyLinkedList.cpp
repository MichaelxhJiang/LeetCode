/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        
        inOrder(root, nullptr, nullptr);
        
        // find leftmost node
        Node* leftNode = root;
        while (leftNode->left != nullptr) leftNode = leftNode->left;
        
        // find rightmost node
        Node* rightNode = root;
        while (rightNode->right != nullptr) rightNode = rightNode->right;
        
        leftNode->left = rightNode;
        rightNode->right = leftNode;
     
        return leftNode;
    }
    
    void inOrder(Node* node, Node* pred, Node* suc) {
        // if left child, this node is successor to child
        // if no left child, link predecessor (nearest right branch parent above) with this node
        if (node->left) {
            inOrder(node->left, pred, node);
            // node->left = node->left;
        } else {
            node->left = pred;
            if (pred) pred->right = node;
        }
        
        // if right child, this node is predecessor to child
        // if no right child, link successor (nearest left branch parent above) with this node
        if (node->right) {
            inOrder(node->right, node, suc);
        } else {
            node->right = suc;
            if (suc) suc->left = node;
        }
    }
};
