class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        unordered_map<char, int> requiredFreq;
        int requiredChars = 0;
        for (char c : t) {
            if (requiredFreq.find(c) == requiredFreq.end()) {
                requiredChars++;
                requiredFreq.insert({c, 1});
            } else {
                requiredFreq[c]++;
            }
            freq.insert({c, 0});
        }
        
        int bestLength = INT_MAX;
        string bestString = "";
        int uniqueChars = 0;
        int li = 0;
        int ri = 0;
        
        while (ri < s.size()) {
            // check if next element is significant
            if (freq.find(s[ri]) != freq.end()) {
                freq[s[ri]]++;
                
                // we have fulfilled the requirement for a new character
                if (freq[s[ri]] == requiredFreq[s[ri]]) uniqueChars++;
            }
            
            // check if we can shrink left index
            while (uniqueChars == requiredChars && li <= ri) {
                if (bestLength > ri - li + 1) {
                    bestLength = ri - li + 1;
                    bestString = s.substr(li, bestLength);
                }
                
                if (freq.find(s[li]) != freq.end()) {
                    freq[s[li]]--;
                    
                    // we have removed a necessary character
                    if (freq[s[li]] < requiredFreq[s[li]]) uniqueChars--;
                }
                
                li++;
            }
            
            ri++;
        }
        
        return bestString;
    }
};
