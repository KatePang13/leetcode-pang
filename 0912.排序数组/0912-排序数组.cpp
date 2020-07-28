class Solution {
    vector<int> tmp;
public:
    vector<int> sortArray(vector<int>& nums) {
        tmp = vector<int>(nums.size(), 0);
        msort(nums, 0, nums.size() - 1);
        return nums;
    }

    void msort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + r >> 1;
        msort(nums, l, mid);
        msort(nums, mid + 1, r);

        int i = l, j = mid + 1, cnt = 0;
        while (i <= mid && j <= r) {
            tmp[cnt++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
        }
        while (i <= mid) {
            tmp[cnt++] = nums[i++];
        } 
        while (j <= r) {
            tmp[cnt++] = nums[j++];
        }
        for (i = 0; i < r - l + 1; ++i) {
            nums[l + i] = tmp[i];
        }
    }
};