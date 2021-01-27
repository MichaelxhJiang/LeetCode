class Solution {
public:
    bool isPalindrome(string s) {
        string clean;
        for (char c : s) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                clean += tolower(c);
            }
        }
        
        string cleanReverse = clean;
        reverse(cleanReverse.begin(), cleanReverse.end());
        
        if (clean == cleanReverse) {
            return true;
        }
        
        return false;
    }
};
