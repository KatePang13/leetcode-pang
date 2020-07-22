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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if( !root ) {
            return ans;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool zigzag = true;
        TreeNode* tmp = nullptr;

        while( !dq.empty() ) {
            int n = dq.size();
            vector<int> tmpVec(n);
            for( int i=0; i<n; i++) {
                tmpVec[i] = handle(dq, zigzag);
            }
            ans.push_back(tmpVec);
            zigzag = !zigzag;
        }

        return ans;
    }

    int handle(deque<TreeNode*>& dq, bool zigzag) {
        TreeNode* node = nullptr;
        if (zigzag) { // 前取后放
            node = dq.front();
            dq.pop_front();
            if (node->left) dq.push_back(node->left); // 下一层顺序存放至尾
            if (node->right) dq.push_back(node->right);                
        } else { // 后取前放
            node = dq.back();
            dq.pop_back();
            if (node->right) dq.push_front(node->right); // 下一层逆序存放至首
            if (node->left) dq.push_front(node->left);
        }
        return node->val;
    }

};