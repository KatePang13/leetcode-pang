/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int low;
    int high;
    int sum;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        this->low = low;
        this->high = high;
        dfs(root);
        return sum;
    }

    void dfs( TreeNode* root) {
        if( !root ) {
            return;
        }

        if( low <= root->val && root->val <= high ) {
            sum += root->val;
        }
        if( low < root->val ) {
            dfs(root->left);
        }
        if( high > root->val ) {
            dfs(root->right);
        }
    }
};
// @lc code=end

