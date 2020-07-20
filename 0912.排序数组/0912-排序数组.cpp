class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if( l < r ) {
            int mid = partition(nums, l, r);
            quickSort(nums, l, mid-1);
            quickSort(nums, mid+1, r);
        }
    }

    int partition(vector<int>& nums, int l, int r) {
        int thor = nums[l];
        int i = l+1;
        int j = r;

        while(1) {
            while( i<=j && nums[i] <= thor ) {
                i++;
            }
            while( i<=j && nums[j] >= thor ) {
                j--;
            }
            if( i>=j ) {
                break;
            }
            swap( nums[i], nums[j] );
        }

        swap(nums[l], nums[j]);
        return j;
    }
};