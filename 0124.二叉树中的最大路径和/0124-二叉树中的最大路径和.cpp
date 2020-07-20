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
private:
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* root) {
        if( !root ) {
            return 0;
        }

        int leftSum = max(dfs(root->left), 0);
        int rightSum = max(dfs(root->right),0);
        int sum = root->val + leftSum + rightSum;
        maxSum = max(maxSum, sum);
        return root->val + max(leftSum, rightSum);
    }
};