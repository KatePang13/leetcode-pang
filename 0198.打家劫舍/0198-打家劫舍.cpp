class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) {
            return 0;
        }
        if( n ==1 ) {
            return nums[0];
        }

        vector<int> f(n+1);
        f[0] = 0;
        f[1] = nums[0];

        for( int i=1; i<n; i++) {
            f[i+1] = max( f[i], f[i-1] + nums[i]);
        }

        return f[n];
    }
};