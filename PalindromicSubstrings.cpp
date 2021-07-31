class Solution {
public:
    int countSubstrings(string s) {
        // n^2 unique substrings worst case
        // determine a string is a palindrome: O(n)
        // use dp so we don't check palindrome of same string twice
        // a palindrome is built from a smaller palindrome
        // dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
        int ans = s.size();        
        vector<vector<bool>> dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) dp[i][i] = true;

        for (int i = 1; i < s.size(); i++) {
            for (int j = 0; j < s.size()-i; j++) {
                if (j+1 <= j+i-1) {
                    dp[j][j+i] = dp[j+1][j+i-1] && s[j]==s[j+i];
                } else {
                    dp[j][j+i] = s[j]==s[j+i];
                }
                if (dp[j][j+i]) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
