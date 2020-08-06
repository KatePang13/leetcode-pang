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
    ListNode* oddEvenList(ListNode* head) {
        ListNode tmpOddHead(0);
        ListNode tmpevenHead(0);

        int i = 1;
        ListNode* pNode = head;
        ListNode* pOdd = &tmpOddHead;
        ListNode* pEven = &tmpevenHead;

        while( pNode ) {
            if( i%2 ) {
                pOdd->next = pNode;
                pOdd = pOdd->next;
            } else {
                pEven->next = pNode;
                pEven = pEven->next;
            }
            pNode = pNode->next;
            i++;
        }

        pEven->next = nullptr;
        pOdd->next = tmpevenHead.next;
        return tmpOddHead.next;
    }
};