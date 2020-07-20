class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int minSubLen = n+1;

        int l = 0;
        int r = 0;
        int sum = 0; 
        while( r < n ) {
            sum += nums[r];
            while( sum >= s ) {
                minSubLen = min( minSubLen, r-l+1 );
                sum -= nums[l];
                l++;
            }
            r++;
        }

        return (minSubLen < n+1) ?  minSubLen : 0;
    }
};