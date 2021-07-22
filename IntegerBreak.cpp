class Solution {
public:
    vector<int> dp;
    
    int integerBreak(int n) {
        dp = vector<int>(60, -1);
        return recur(n, false);
    }
    
    int recur(int n, bool minSplit) {
        if (dp[n] != -1) return dp[n];
        if (n == 0) {
            return 1;
        }
        int maxMult = minSplit ? n : 1;
        int maxInt = 1;
        for (int i = 1; i < n; i++) {
            int res = recur(n-i, true);
            if (i*res > maxInt*maxMult) {
                maxMult = res;
                maxInt = i;
            }
        }
        dp[n] = maxInt*maxMult;
        return maxInt*maxMult;
    }
};
