class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) {
            return 0;
        }
        if( n == 1 ) {
            return nums[0];
        }
        vector<vector<int>> f(n, vector<int>(2) );  //f[i][0] 包含 nums[0]的情况， f[i][1] 不包含 nums[0]的情况;
        f[0][0] = nums[0];
        f[0][1] = 0;
        f[1][0] = max(nums[0], nums[1]);
        f[1][1] = nums[1];

        for( int i=2; i<n; i++) {
            f[i][0] = max( f[i-1][0], f[i-2][0] + nums[i] );
            f[i][1] = max( f[i-1][1], f[i-2][1] + nums[i] );
        }
        
        return max( f[n-2][0], f[n-1][1]);
    }
};