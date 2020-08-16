class Solution {
    int can(vector<int>&a, int c) {
        int la = -1000000000;
        int S = 0;
        for (auto i : a)
            if (i-la >= c) {
                S ++;
                la = i;
            }
        return S;
    }
public:
    int maxDistance(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int le = 0, ri = 1000000000;
        while (le <= ri) {
            int mid = (le+ri)/2;
            if (can(a, mid) >= m) le = mid+1;
            else ri = mid-1;
        }
        return ri;
    }
};