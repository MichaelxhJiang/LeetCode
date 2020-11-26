class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unsigned int length = amount + 1;
        vector<int> dp(length, -1);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            if (dp[i] != -1) {
                for (long long coin : coins) {
                    if (i + coin > amount) continue;
                    
                    if (dp[i + coin] == -1)
                        dp[i + coin] = dp[i] + 1;
                    else
                        dp[i + coin] = min(dp[i + coin], dp[i] + 1);
                }
            }
        }
        
        return dp[amount];
    }
};
