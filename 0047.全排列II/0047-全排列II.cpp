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

        //��¼�ڸý׶��У�ĳ��Ԫ��ֵ�Ƿ��Ѿ���ʹ�ù�����������ظ�;���� 1�ڵ�һλʹ���ˣ�1�Ͳ����ڵ�һλ���ֵڶ���;
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