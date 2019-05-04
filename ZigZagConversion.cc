class Solution {
public:
    string convert(string s, int numRows) {
        string rows[numRows];
        
        for (int i = 0; i < numRows; i++) rows[i] = "";
        
        bool zig = true; //vertical part of pattern
        int row = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (zig) {
                rows[row] += s.substr(i, 1);
                row++;
                
                if (row == numRows) {
                    if (numRows > 2) zig = false;
                    if (numRows >= 2) row = numRows-2;
                    else row = 0;
                }
            } else {
                rows[row] += s.substr(i, 1);
                row--;
                
                if (row == 0) {
                    zig = true;
                }
            }
        }
        
        string ans = "";
        
        for (int i = 0; i < numRows; i++) {
            ans += rows[i];
        }
        
        return ans;
    }
};
