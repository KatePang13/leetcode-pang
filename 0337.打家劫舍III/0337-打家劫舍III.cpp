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
    int rob(TreeNode* root) {    
        auto result = dfs(root);
        return result.first;
    }

    pair<int, int> dfs( TreeNode* root) {
        if( !root ) {
            return {0, 0};
        }

        auto leftResult = dfs(root->left);
        auto rightResult = dfs(root->right);

        int curWithSelf = root->val + leftResult.second + rightResult.second;
        int curWithoutSelf = leftResult.first + rightResult.first;
        int curMax = max( curWithSelf, curWithoutSelf );
        return { curMax, curWithoutSelf};
    }
};