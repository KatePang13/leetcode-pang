class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if( l < r ) {
            int mid = apartion(nums, l, r);
            quickSort(nums, l, mid-1);
            quickSort(nums, mid+1, r);
        }
    }

    int apartion(vector<int>& nums, int l, int r) {
        int thro = nums[l];

        while( l < r ) {
            while( r>l && nums[r] >= thro ) {
                r--;
            }
            nums[l] = nums[r];
            while( r>l && nums[l] <= thro ) {
                l++;
            }
            nums[r] = nums[l];
        }

        nums[l] = thro;
        return l;       
    }
};