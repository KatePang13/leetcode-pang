class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, int> freqs;
        for( int i : nums ) {
            freqs[i]++;
        }

        for( auto [i , freq] : freqs ) {
            if( freq > n/2 ) {
                return i;
            } 
        }

        return -1;
    }
};