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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> res;
        if(root==NULL) return res;//递归出口，当root为空时，返回空
        if(root->left==NULL&&root->right==NULL) {//当root为叶子节点时，将叶子结点的val放入res，再返回
            res.push_back(to_string(root->val)); 
            return res;
        }
        vector <string> lefts=binaryTreePaths(root->left);//递归过程
        for(int i=0;i<lefts.size();i++) {//求左子树的路径
            res.push_back(to_string(root->val)+"->"+lefts[i]);//将根节点的值放入res，按题目要求储存
        }
        vector <string> rights=binaryTreePaths(root->right);//求右子树的路径
        for(int i=0;i<rights.size();i++) {
            res.push_back(to_string(root->val)+"->"+rights[i]);
        }
        return res;
    }
};