class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return recursiveHelper(s, p, 0, 0, dp);
    }
    
    bool recursiveHelper(string s, string p, int si, int pi, vector<vector<int>>& dp) {
        if (dp[si][pi] != -1) return dp[si][pi] == 1;
        if (p.size() == 0) return s.size() == 0;
        
        bool match = s.size() != 0 && (s[0] == p[0] || p[0] == '.');
        
        if (p.size() > 1 && p[1] == '*') {
            // try using * or skipping it
            bool result = (match && recursiveHelper(s.substr(1), p, si+1, pi, dp)) || recursiveHelper(s, p.substr(2), si, pi+2, dp);
            dp[si][pi] = result ? 1 : 0;
            return result;
        } else {
            bool result = match && recursiveHelper(s.substr(1), p.substr(1), si+1, pi+1, dp);
            dp[si][pi] = result ? 1 : 0;
            return result;
        }
    }
};
