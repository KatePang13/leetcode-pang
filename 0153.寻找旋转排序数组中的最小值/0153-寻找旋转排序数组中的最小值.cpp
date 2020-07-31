class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while(start+1<end) //判断条件也可以写成start<end,无所谓看个人习惯，只要在最后加以处理就行
        {
            int mid=(start+end)>>1;
            if(nums[mid]<nums[end])
            {
                end=mid;
            }
            else if(nums[mid]>nums[end])
            {
                start=mid;
            }
        }
        return min(nums[start],nums[end]);//最后答案定位在了两个数字，小的那个即为答案
    }
};