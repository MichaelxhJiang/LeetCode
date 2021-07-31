class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // DP solution
        // Build larger squares using smaller squares
        // dp[i][j] = max length of square where i,j is bottom right corner
        // dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i][j-1])
        // the key is to figure out how to build larger squares from smaller squares
        // eg. a 3x3 can be built with a 1 on bottom right (i, j), 
        // a 2x2 at i-1, j, a 2x2 at i-1, j-1, and a 2x2 at i,j-1
        vector<vector<int>> dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j]-'0';
                } else if (matrix[i][j]-'0' == 1) {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                } else {
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]*dp[i][j]);
            }
        }
        
        return ans;
    }
};
