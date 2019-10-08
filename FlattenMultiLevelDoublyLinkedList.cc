/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> parents;
        
        flattenList(head, parents);
        
        return head;
    }
    
    void flattenList(Node* head, stack<Node*>& parents) {
        Node* cur = head;
        Node* prevCur = head;
        
        while (cur != nullptr) {
            if (cur->child != nullptr) {
                parents.push(cur);
                flattenList(cur->child, parents);
            }
            
            prevCur = cur;
            cur = cur->next;
        }
        
        if (parents.size() != 0) {
            Node* parent = parents.top(); 
            parents.pop();
            
            Node* nextNode = parent->next;
            parent->next = head;
            parent->child = nullptr;
            head->prev = parent;
            
            if (nextNode != nullptr) {
                nextNode->prev = prevCur;
                prevCur->next = nextNode;
            }
        }
    }
};
