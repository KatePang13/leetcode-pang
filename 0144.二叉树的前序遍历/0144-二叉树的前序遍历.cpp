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

    void travel( TreeNode* root, vector<int>& buf ){
        if( root == NULL ){
            return ;
        }

        buf.push_back( root->val );
        travel(root->left, buf);
        travel(root->right, buf);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        travel( root, ans );
        return ans;
    }
};