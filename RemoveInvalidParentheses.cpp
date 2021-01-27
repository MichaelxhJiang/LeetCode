class Solution {
public:
    set<string> ans;
    
    vector<string> removeInvalidParentheses(string s) {
        int leftDeletes = 0;
        int rightDeletes = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                leftDeletes++;
            } else if (s[i] == ')') {
                if (leftDeletes > 0) leftDeletes--;
                else rightDeletes++;
            }
        }
        
        recur(s, 0, 0, 0, leftDeletes, rightDeletes, "");
        
        vector<string> v(ans.begin(), ans.end());
        return v;
    }
    
    void recur(string s, int index, int left, int right, int leftToDelete, int rightToDelete, string expression) {
        if (index == s.size() && leftToDelete == 0 && rightToDelete == 0) {
            ans.insert(expression);
        }
        
        if (index < s.size()) {
            // we can choose to skip this character (if parentheses), or add this character
            
            // try skipping
            if ((s[index] == '(' && leftToDelete > 0) || (s[index] == ')' && rightToDelete > 0)) {
                recur(
                    s, 
                    index+1, 
                    left, 
                    right, 
                    leftToDelete - (s[index] == '(' ? 1 : 0), 
                    rightToDelete - (s[index] == ')' ? 1 : 0), 
                    expression
                );
            } 
            
            // try including
            expression += s[index];
            if (s[index] == '(') {
                recur(s, index+1, left+1, right, leftToDelete, rightToDelete, expression);
            } else if (s[index] == ')') {
                if (left > right) {
                    recur(s, index+1, left, right+1, leftToDelete, rightToDelete, expression);
                }
            } else {
                recur(s, index+1, left, right, leftToDelete, rightToDelete, expression);
            }
            
            // remove due to backtracking
            expression.pop_back();
        }
    }
};
