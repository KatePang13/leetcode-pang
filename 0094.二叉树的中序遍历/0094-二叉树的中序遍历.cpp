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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTravel(root, ans);
        return ans;
    }

    void inorderTravel(TreeNode* root, vector<int>& vec){
        if( !root ){
            return ;
        }

        inorderTravel(root->left, vec);
        vec.push_back( root->val);
        inorderTravel(root->right, vec);
    }

};