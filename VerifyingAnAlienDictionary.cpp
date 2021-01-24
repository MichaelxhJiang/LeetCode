class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < words.size()-1; i++) {
            int length = min(words[i].length(), words[i+1].length());
            bool same = true;
            for (int j = 0; j < length; j++) {
                if (words[i][j] != words[i+1][j]) {
                    cout << i<< endl;
                    same = false;
                    for (char c : order) {
                        if (c == words[i][j]) break;
                        else if (c == words[i+1][j]) return false;
                    }
                    break;
                }
            }
            if (same && words[i].length() > words[i+1].length()) return false;
        }
        
        return true;
    }
};
