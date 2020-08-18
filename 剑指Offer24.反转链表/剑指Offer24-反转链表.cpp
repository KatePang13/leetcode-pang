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
    ListNode* reverseList(ListNode* node, ListNode* pre){
        ListNode* next = node->next;
        node->next = pre;
        if(!next)
            return node;

        return reverseList(next, node);
    }

    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
            
        return reverseList(head, NULL);
    }
};