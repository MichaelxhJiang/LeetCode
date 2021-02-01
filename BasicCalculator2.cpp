class Solution {
public:        
    int calculate(string s) {
        int ans = 0;
        stack<int> stack;
        int curNum = 0;
        char prevOp = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                curNum = curNum*10 + (s[i]-'0');
            }
            
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size()-1) {
                if (prevOp == '+') {
                    stack.push(curNum);
                } else if (prevOp == '-') {
                    stack.push(-curNum);
                } else if (prevOp == '*') {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top*curNum);
                } else {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top/curNum);
                }
                prevOp = s[i];
                curNum = 0;
            }
        }
        
        while (!stack.empty()) {
            int top = stack.top();
            stack.pop();
            ans += top;
        }
        
        return ans;
    }
};
