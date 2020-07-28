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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if( !root ) {
            return ans;
        }

        queue< pair<TreeNode*, int> > q;
        q.push( {root, 0} );
        vector<int> nums;
        int lastLevel = 0;

        while( !q.empty() ) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if( lastLevel != level ) {
                compute(nums, ans);
                nums.clear();
                lastLevel = level;
            }
            nums.push_back(node->val);

            if( node->left ) {
                q.push({node->left, level+1});
            } 
            if( node->right ) {
                q.push({node->right, level+1});
            }
        }

        compute(nums, ans);
        return ans;
    }

    void compute(vector<int>& nums, vector<double>& ans) {
            int n = nums.size();
            if( n == 0 ) {
                return ;
            }

            long long sum = 0;
            for( auto num : nums ) {
                sum += num;
            }
            double avg = double(sum) / n;
            ans.push_back(avg);
    } 

};