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
    ListNode* swapPairs(ListNode* head) {
        ListNode tmphead(0);
        tmphead.next = head;
        ListNode* prev = &tmphead;
        ListNode* slow = head;
        ListNode* fast = NULL;
        if( slow ) {
            fast = slow->next;
        }

        while( fast ) {
            ListNode* next = fast->next;
            prev->next = fast;
            fast->next = slow;
            slow->next = next;

            if( !slow->next ) {
                break;
            }
            if(!slow->next->next) {
                break;
            }

            prev = slow;
            slow = slow->next;
            fast = slow->next;
        }

        return tmphead.next;
    }
};