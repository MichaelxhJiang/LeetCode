class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // sort to ensure that we can only have predecessors in left side of array
        // so dp map gurantees that all smaller words are fully solved
        // so we can build up our chain from small to large words
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });
        
        unordered_map<string, int> dp;
        for (string w : words) dp.insert({w, 1});
        
        int ans = 1;
        for (int i = 0; i < words.size(); i++) {
            // try deleting each character and checking if resulting
            // string is a predecessor. This is faster than iterating
            // over all words and checking if the pair is a predecessor
            // since length of a word < 16 while number of words < 1000
            for (int k = 0; k < words[i].size(); k++) {
                string pred = words[i].substr(0, k) + words[i].substr(k+1);
                if (dp.find(pred) != dp.end()) {
                    dp[words[i]] = max(dp[words[i]], dp[pred]+1);
                }
            }
            ans = max(ans, dp[words[i]]);
        }
    
        return ans;
    }
};
