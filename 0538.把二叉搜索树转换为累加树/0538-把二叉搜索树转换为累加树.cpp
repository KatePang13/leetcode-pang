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
    int prev; 
public:
    TreeNode* convertBST(TreeNode* root) {
        if( !root ) {
            return root;
        }
        prev = 0;
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root) {
        if( !root ) {
            return ;
        }

        dfs(root->right);
        root->val += prev;
        prev = root->val;
        dfs(root->left);
    }

};