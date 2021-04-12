class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
            long sx = 10;
            long sy = 10;
            while( sx <= x ) {
                sx *= 10;
            }
            while( sy <= y ) {
                sy *= 10;
            }
            
            return x*sy + y > y*sx + x;
        } );

        if( nums[0] == 0 ) {
            return "0";
        }

        for( int num : nums ) {
            ans += to_string(num);
        }

        return ans;
    }
};