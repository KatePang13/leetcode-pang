class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount +1;
        vector<int> dp( Max, Max );
        dp[0] = 0;

        for( int i =1; i<= amount; i++ ){
            for( auto j : coins ){
                if( j <= i ){
                    dp[i] = min( dp[i], dp[i-j]+1 );
                }
            }
        }

        return (dp[amount] > amount) ? -1 : dp[amount] ;

    }
};