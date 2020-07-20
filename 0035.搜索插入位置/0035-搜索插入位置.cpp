class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if( n == 0 ) {
            return 0;
        }

        if( nums[0] > target ) {
            return 0;
        }
        if( nums[n-1] < target ) {
            return n;
        }

        int ans = 0;
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;

        while( left <= right ) {
            int mid = left + (right-left+1)/2;
            if( nums[mid] == target ) {
                return mid;
            } else if( nums[mid] < target ) {
                left = mid + 1;
            } else {
                right = mid - 1;
                ans = mid;
            }
        }

        return ans;
    }
};