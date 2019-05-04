class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[100][100] = {0};
        int ans = solve(m, n, 0, 0, dp);
        
        return ans;
    }
    
    int solve(const int& m, const int& n, int x, int y, int (&dp) [100][100]) {
        int ans = 0;
        if (x == m-1 && y == n-1) {
            ans = 1;
        } else if (x == m-1) {
            if (dp[y+1][x] != 0) ans = dp[y+1][x];
            else ans = solve(m, n, x, y+1, dp);
        } else if (y == n-1) {
            if (dp[y][x+1] != 0) ans = dp[y][x+1];
            else ans = solve(m, n, x+1, y, dp);
        } else {
            if (dp[y+1][x] != 0) ans = dp[y+1][x];
            else ans = solve(m, n, x, y+1, dp);
            
            if (dp[y][x+1] != 0) ans += dp[y][x+1];
            else ans += solve(m, n, x+1, y, dp);
        }
        
        dp[y][x] = ans;
        return ans;
    }
};
