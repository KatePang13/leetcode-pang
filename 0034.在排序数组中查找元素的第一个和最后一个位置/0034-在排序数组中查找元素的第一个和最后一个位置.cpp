class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if( n == 0 ) {
            return {-1, -1};
        }
 
        int begIdx = searchBeginIndex(nums, target);
        if( begIdx == -1 ) {
            return {-1, -1};
        }
        int endIdx = searchEndIndex(nums, target);
        return {begIdx, endIdx};
    }

    int searchBeginIndex(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while( l < r ) {
            int mid = l+ (r-l)/2;
            // [..,mid] 都是 < target, 砍掉; 
            if( nums[mid] < target ) {
                l = mid +1;
            } else {
                r = mid;
            }
        }
        if( nums[l] == target ) {
            return l;
        }
        return -1;
    }

    int searchEndIndex(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while( l < r ) {
            int mid = l + (r-l+1)/2;
            // [mid,..] 都是> target, 砍掉; 
            if( nums[mid] > target ) {
                r = mid-1;
            } else {
                l = mid;
            }
        }
        if( nums[l] == target ) {
            return l;
        }
        return -1;
    }

};