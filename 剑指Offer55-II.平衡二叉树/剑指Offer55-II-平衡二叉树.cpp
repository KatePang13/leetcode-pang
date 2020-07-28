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
    bool vaild;
public:
    bool isBalanced(TreeNode* root) {
        vaild = true;
        dfs(root);
        return vaild;
    }

    int dfs(TreeNode* root) {
        if( !root ) {
            return 0;
        }
        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);
        if( abs( leftDepth-rightDepth ) > 1 ) {
            vaild = false;
        }
        return max(leftDepth, rightDepth) + 1;
    }
};