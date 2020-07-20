class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int index = searchBinary(nums, target) ;
        if( index == -1 ) {
            return {-1, -1};
        }

        int left = index-1;
        int right = index+1;
        while( left >=0 && nums[left] == nums[index] ) {
            left--;
        }

        while( right<n && nums[right] == nums[index] ) {
            right++;
        }

        return {left+1, right-1};
    }

    int searchBinary(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while( left <= right ) {
            int mid = left + (right-left+1)/2;
            if( nums[mid] == target ) {
                return mid;
            }

            if( nums[mid] < target ) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

};