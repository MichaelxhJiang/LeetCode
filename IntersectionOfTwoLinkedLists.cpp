/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // other method is hashmaps to store traversed pointers
        
        // two pointers, each pointer traverses both linked lists once
        // if both pointers traverse both lists, then the distance they travel
        // to the intersection will be the same:
        // list A = preA + inter + post
        // list B = preB + inter + post
        // preA + inter + post + preB + inter = preB + inter + post + preA + inter
        
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            
            if (p1 == p2) {
                return p1;
            }
            if (p1 == nullptr) {
                p1 = headB;
            }
            if (p2 == nullptr) {
                p2 = headA;
            }
        }
        
        return p1;
    }
};
