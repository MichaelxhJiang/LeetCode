class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        // 3d dp - dp[day][transaction][holding/notholding] - max profit up to this state
        // keep holding stock
        // dp[i][j][1] = dp[i-1][j][1]
        // sell a stock
        // dp[i][j][0] = dp[i-1][j][1] + prices[i]
        // buy a stock
        // dp[i][j][1] = dp[i-1][j-1][0] - prices[i]
        // not holding, don't do anything
        // dp[i][j][0] = dp[i-1][j][0]
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(prices.size(), vector<vector<int>>(k+2, vector<int>(2, -1000000000)));
        // on first day, can only buy or not do anything
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j <= k; j++) {
                // continue not holding or sell
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                // continue holding or buy
                if (j > 0) {
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i <= k; i++) {
            ans = max(ans, dp[prices.size()-1][i][0]);
        }
        return ans;
    }
};
