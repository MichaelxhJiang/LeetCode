class Solution {
public:
    unordered_map<string, vector<string>> dp;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return helper(s, wordDict);
    }
    
    vector<string> helper(string s, vector<string>& wordDict) {
        if (s == "") return vector<string>{""};

        if (dp.find(s) != dp.end()) {
            return dp[s];
        }
        
        vector<string> ans;

        // check which words we can form from prefix
        for (string word : wordDict) {
            if (s.rfind(word, 0) == 0) {
                vector<string> res = helper(s.substr(word.size()), wordDict);
                for (string r : res) {
                    if (r == "") {
                        // we found a complete sentence
                        ans.push_back(word);
                    } else {
                        ans.push_back(word + " " + r);
                    }
                }
            }
        }
        
        dp.insert({s, ans});
        
        return ans;
    }
};
