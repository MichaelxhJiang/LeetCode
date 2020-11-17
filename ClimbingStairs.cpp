class Solution {
public:
    
    // int recurseStep(int n, int step, vector<int>& memo) {
    //     if (memo[step] != -1) {
    //         return memo[step];
    //     }
    //     if (step == n) {
    //         return 1;
    //     } else if (step > n) {
    //         return 0;
    //     } else {
    //         int ans = recurseStep(n, step + 1, memo) + recurseStep(n, step + 2, memo);
    //         memo[step] = ans;
    //         return ans;
    //     }
    // }
    
    int climbStairs(int n) {
        // vector<int> memo (50, -1);
        // return recurseStep(n, 0, memo);
        int dp[46];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};
