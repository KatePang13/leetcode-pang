class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<int> pos[26];
        for (int i = 0; i < ring.size(); i++) {
            pos[ring[i] - 'a'].push_back(i);
        }

        vector<vector<int>> dp(key.size(), vector<int>(ring.size(), INT_MAX));
        for (int i = 0; i < key.size(); i++) {
            for (auto j : pos[key[i] - 'a']) {
                if (i == 0) {
                    dp[i][j] = min(dp[i][j], 0 + clac(ring.size(), 0, j) + 1);
                    continue;
                }
                
                for (auto k : pos[key[i - 1] - 'a']) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + clac(ring.size(), k, j) + 1);
                }
            }
        }

        return *min_element(dp.back().begin(), dp.back().end());
    }

    int clac(int len, int a, int b) {
        return min((len + a - b) % len, (len + b - a) % len);
    }
};