/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        
        // bfs traversal
        queue<Node*> q;  // <original node to be traversed, new node parent>
        q.push(node);
        
        unordered_map<Node*, Node*> visited;
        Node* root = new Node(node->val);
        visited.insert({node, root});
        
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            
            for (auto& v : cur->neighbors) {
                if (visited.find(v) == visited.end()) {
                    Node* newNode = new Node(v->val);
                    visited.insert({v, newNode});
                    q.push(v);
                }
                
                visited[cur]->neighbors.push_back(visited[v]);
            }
        }
        
        return visited[node];
    }
};
