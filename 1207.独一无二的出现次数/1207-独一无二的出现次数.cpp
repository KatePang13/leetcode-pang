class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> countMap;
        set<int> countSet;

        for( int num : arr ) {
            countMap[num]++;
        }


        for( auto [num, count] : countMap ) {
            if( countSet.count(count) ) {
                return false;
            }
            countSet.insert(count);
        }

        return true;
    }
};