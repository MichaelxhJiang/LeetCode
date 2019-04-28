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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        
        ListNode* result = nullptr;
        ListNode* head = nullptr;
        
        int carry = 0;
        
        while (cur1 != nullptr && cur2 != nullptr) {
            int sum = cur1->val + cur2->val + carry;
            
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            
            ListNode* newNode = new ListNode(sum);
            
            if (result == nullptr) {
                result = newNode;
                head = newNode;
            } else {
                result->next = newNode;
                result = result->next;
            }
                
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        
        while (cur1 != nullptr) {
            int sum = cur1->val + carry;
            if (sum > 9) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            result->next = newNode;
            result = result->next;
            
            cur1 = cur1->next;
        }
        
        
        while (cur2 != nullptr) {
            int sum = cur2->val + carry;
            if (sum > 9) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(sum);
            result->next = newNode;
            result = result->next;
            
            cur2 = cur2->next;
        }
        
        if (carry == 1) {
            ListNode* newNode = new ListNode(1);
            result->next = newNode;
        }
        
        return head;
    }
};
