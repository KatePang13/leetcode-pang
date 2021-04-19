/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int prev = INT_MIN;
        for( int num : nums ) {
            if( num != prev ) {
                nums[i++] = num;
            }
            prev = num;
        }

        return i;
    }
};
// @lc code=end

