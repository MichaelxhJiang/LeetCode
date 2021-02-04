class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> dp (s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(') continue;
            
            // two cases: () and ))
            if (s[i-1] == '(') {
                if (i >= 2) {
                    dp[i] = dp[i-2] + 2;
                } else {
                    dp[i] = 2;
                }
            } else if (i - dp[i-1] - 1 >= 0 && s[i-dp[i-1]-1] == '(') {  //   is this ( -> _(... ))
                dp[i] = dp[i-1] + 2;
                if (i - dp[i-1] - 1 >= 1) {
                    dp[i] += dp[i - dp[i-1] - 2];
                }
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
