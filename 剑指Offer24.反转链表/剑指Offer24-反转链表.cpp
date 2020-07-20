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

    ListNode* reverse( ListNode* cur, ListNode* pre){
        if( !cur ){
            return pre;
        }

        ListNode* next =cur->next;
        cur->next = pre;
        return reverse(next, cur);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse( head, NULL );
    }
};