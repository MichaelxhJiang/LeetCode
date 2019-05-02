class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 1;
        string max = s.substr(0,1);
        
        int arr [1000][1000] = {0};
        for (int i = 0; i < s.size(); i++) {
            arr[i][i] = 1;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[i+1]) {
                arr[i][i+1] = 1;
                if (maxLength < 2) {
                    maxLength = 2;
                    max = s.substr(i,2);
                }
            }
        }
        
        for (int i = 2; i < s.size(); i++) {
            for (int j = 0; j < s.size()-i; j++) {
                if (arr[j+1][j+i-1] && s[j] == s[j+i]) {
                    arr[j][j+i] = 1;
                    if (maxLength < i+1) {
                        maxLength = i+1;
                        max = s.substr(j,i+1);
                    }
                }
            }
        }
        
        return max;
    }
};
