class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort each string's characters
        // use map (sorted string : list of anagrams)
        unordered_map<string, vector<string>> anagramGroups;
        vector<vector<string>> ans;
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (anagramGroups.find(str) == anagramGroups.end()) {
                anagramGroups[str] = vector<string>();
            }
            
            anagramGroups[str].push_back(strs[i]);
        }
        
        // aggregate groups into ans
        for (const auto& group : anagramGroups) {
            ans.push_back(group.second);
        }
        
        return ans;
    }
};
