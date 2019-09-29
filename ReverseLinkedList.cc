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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        
        while (head != NULL) {
            ListNode* node = new ListNode(head->val);
            node->next = newHead;
            newHead = node;
            head = head->next;
        }
        
        return newHead;
    }
};
