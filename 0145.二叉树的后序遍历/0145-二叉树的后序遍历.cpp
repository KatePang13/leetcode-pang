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

        travel( root->left, buf );
        travel( root->right, buf);
        buf.push_back( root->val );
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        travel( root, ans );
        return ans;        
    }
};