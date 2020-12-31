/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* curNode = head;
        
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                ListNode* newNode = new ListNode(l1->val, nullptr);
                curNode->next = newNode;
                curNode = curNode->next;
                l1 = l1->next;
            } else {
                ListNode* newNode = new ListNode(l2->val, nullptr);
                curNode->next = newNode;
                curNode = curNode->next;
                l2 = l2->next;
            }
        }
        
        curNode->next = l1 == nullptr ? l2 : l1;
        
        return head->next;
    }
};
