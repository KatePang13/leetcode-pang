/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        while( !head ) {
            return NULL;
        } 

        //[left][mid][right]寻找中点，划分左右子树;
        //快慢指针，流程结束时,slow指向中间节点;
        //[head, slow->prev, NULL]  [slow] [slow->next, NULL]
        ListNode* slowPrev = NULL;
        ListNode* slow = head;
        ListNode* fast = head->next;
        int leftCount = 0;
        int rightCount = 0;
        while( fast ) {
            slowPrev =slow;
            slow = slow->next;
            leftCount++;

            fast = fast->next;
            if( fast ) {
                fast = fast->next;
                rightCount++;
            }
        }

        TreeNode* root = new TreeNode(slow->val);
        if( leftCount > 0 ) {
            slowPrev->next = NULL;
            root->left = sortedListToBST(head);
        }
        if( rightCount > 0 ) {
            root->right = sortedListToBST( slow->next );
        }

        return root;
    }
};