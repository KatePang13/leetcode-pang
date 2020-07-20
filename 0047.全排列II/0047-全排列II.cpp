class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> buf;
        vector<int> visited(nums.size());
        dfs( nums, res, buf, visited );
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& buf, vector<int>& visited) {
        if( buf.size() == nums.size() ) {
            res.push_back(buf);
            return;
        }

        //记录在该阶段中，某个元素值是否已经被使用过，避免出现重复;例如 1在第一位使用了，1就不能在第一位出现第二次;
        map<int, int> memo;

        for( int i=0; i<nums.size(); i++ ) {
            if( visited[i] != 0 ) {
                continue;
            }
            if( memo.find(nums[i]) != memo.end() ) {
                continue;
            }

            memo[nums[i]] = 1;
            visited[i] = 1;
            buf.push_back(nums[i]);
            dfs(nums, res, buf, visited);
            buf.erase(buf.end()-1);
            visited[i] = 0;
        }
    }
};