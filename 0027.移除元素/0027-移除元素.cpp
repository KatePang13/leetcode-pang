class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        int n = nums.size();
        if( n < 1 ) {
            return len;
        }

        for( int i=0; i<n; i++ ) {
            if( nums[i] == val ) {
                continue;
            }

            nums[len] = nums[i];
            len++;
        }
        return len;
    }
};