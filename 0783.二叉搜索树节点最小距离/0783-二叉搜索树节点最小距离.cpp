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
    int minDiffInBST(TreeNode* root) {
        vector<int> valVec;
        dfs(root, valVec);
        int minDiff = INT_MAX;
        for(int i=1; i<valVec.size(); i++){
            int diff = valVec[i]- valVec[i-1];
            minDiff = min(minDiff, diff); 
        }

        return minDiff;
    }

    void dfs(TreeNode* root, vector<int>& valVec) {
        if( !root ) {
            return;
        }

        dfs(root->left, valVec);
        valVec.push_back(root->val);
        dfs(root->right, valVec);
    }
};