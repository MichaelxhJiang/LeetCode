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

    ListNode* reverseListRecursive(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        //recursively iterate to last node, work backwards
        ListNode* newHead = reverseListRecursive(head->next);
        
        //make the next node point to this node (reverse the)
        head->next->next = head;
        
        //remove original link
        head->next = NULL;
        
        return newHead;
    }
};
