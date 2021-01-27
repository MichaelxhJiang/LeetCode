class Solution {
public:
    bool validPalindrome(string s) {
        bool ans = true;
        int bound = s.size()/2;
        int size = s.size();
        for (int i = 0; i < bound; i++) {
            if (s[i] != s[size-1-i]) {
                int j = size-1-i;
                ans = checkValid(s, i, j-1) || checkValid(s, i+1, j);
                break;
            }
        }
        
        return ans;
    }
    
    bool checkValid(string& s, int i, int j) {
        int bound = i + (j - i)/2;
        for (int k = i; k <= bound; k++) {
            if (s[k] != s[j - k + i]) {
                return false;
            }
        }
        
        return true;
    }
};
