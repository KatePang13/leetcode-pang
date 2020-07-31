class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        if( nums[r] < target ) {
            return n;
        }

        int mid = 0;
        while( l < r ) {
            mid = l + (r-l)/2;
            if( nums[mid] < target ) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};