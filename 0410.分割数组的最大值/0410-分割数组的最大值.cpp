class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<long long>> f(n+1, vector<long long>(m+1, LLONG_MAX));
        vector<long long> prevSum(n+1);
        f[0][0] = 0;
        long long tmp = 0;

        for( int i=0; i<n; i++ ) {
            prevSum[i+1] =  prevSum[i] + nums[i];  
        }

        for( int i=1; i<=n; i++ ) {
            for( int j=1; j<= min(i, m); j++ ) {
                for( int k=0; k<i; k++) {
                    tmp = max( f[k][j-1], prevSum[i] - prevSum[k]);
                    f[i][j] = min( tmp, f[i][j]);
                }
            }
        }

        return f[n][m];
    }
};