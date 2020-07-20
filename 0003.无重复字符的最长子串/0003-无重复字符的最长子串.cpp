class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if( s.size() == 0 ){
            return 0;
        }

        unordered_set<char> cache;
        int ans = 0;
        int left = 0;

        for( int i =0; i< s.size(); i++ ){
            while( cache.find(s[i]) != cache.end() ){
                cache.erase(s[left]);
                left++;
            }
            ans = max( ans, i-left+1 );
            cache.insert(s[i]);
        }

        return ans;
    }
};