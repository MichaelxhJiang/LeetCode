class Solution {
public:
    int fixedSize;
    vector<string> ans;
    
    vector<string> generateParenthesis(int n) {
        fixedSize = n*2;
        helper(n, 0, "");
        return ans;
    }
    
    void helper(int n, int depth, string cur) {
        if (n == 0) {
            while (cur.size() < fixedSize) cur += ")";
            ans.push_back(cur);
        } else {
            if (depth != 0) {
                helper(n, depth-1, cur + ")");
            }
            helper(n-1, depth+1, cur + "(");
        }
    } 
};
