class Solution {
public:
    vector<vector<int>> rec;
    vector<int> val;
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n+2);
        
        //�������һ��1;
        val[0] = 1;
        val[n+1] = 1;
        for( int i=0; i<n; i++ ) {
            val[i+1] = nums[i];
        }
        
        rec.resize(n+2, vector<int>(n+2, -1));
        return solve(0, n+1);
    }

    int solve(int left, int right) {
        if( left >= right -1 ) {
            return 0;
        }
        if( rec[left][right] != -1 ) {
            return rec[left][right];
        }
        for( int i=left+1; i<right; i++ ) {
            int sum = val[left]*val[i]*val[right];
            sum += solve(left, i) + solve(i, right);
            rec[left][right] = max(rec[left][right], sum);
        }
        return rec[left][right];
    }

};