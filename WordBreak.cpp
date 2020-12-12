class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int minLength = INT_MAX;
        int maxLength = 0;
        for (string word : wordDict) {
            minLength = min(minLength, (int)word.length());
            maxLength = max(maxLength, (int)word.length());
        }
        unordered_map<string, bool> memo;
        return recur(s, wordDict, minLength, maxLength, memo);
    }
    
    bool recur(string s, vector<string>& wordDict, int minLength, int maxLength, unordered_map<string, bool>& memo) {
        if (s == "") return true;
        
        if (memo.find(s) != memo.end()) return memo[s];
        
        bool ans = false;
        int max = min(maxLength, (int)s.length());  
        for (int i = minLength; i <= max; i++) {
            if (find(wordDict.begin(), wordDict.end(), s.substr(0, i)) != wordDict.end()) {
                bool result = recur(s.substr(i), wordDict, minLength, maxLength, memo);
                ans = ans || result;
            }
        }
        memo.insert({s, ans});
        return ans;
    }
};
