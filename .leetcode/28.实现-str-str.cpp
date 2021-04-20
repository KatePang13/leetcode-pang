/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();

        if( m < n ) {
            return -1;
        }

        if( n == 0 ) {
            return 0;
        }

        for( int i=0; i<m; i++ ) {
            if( m-i < n ) {
                return -1;
            }

            int k = i;
            int j = 0;
            while( haystack[k] == needle[j] ) {
                k++;
                j++;
                if( j == n ) {
                    return i;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

