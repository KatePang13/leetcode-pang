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
    ListNode* reverse(ListNode* current, ListNode* next,ListNode** end, int m, int n ,int step)
    {
        if( step == n)
        {
            *end = next;
            return current;
        }

        ListNode* newstart = reverse(next,next->next,end, m,n, step+1);
        next->next = current;
        
        return newstart;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode tmphead(0);
        tmphead.next = head;
        ListNode *current = &tmphead;
        ListNode *pre = NULL;
        ListNode* end = NULL;

        int i = 0;

        for(;i<m; i++)
        {
            pre = current;
            current = current->next;
        }

        ListNode* newstart = reverse(current,current->next, &end, m , n, i);
        pre->next->next = end;
        pre->next= newstart;
        return tmphead.next;
    }

    
};