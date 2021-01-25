class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stack; // store indices of open parenthesis
        unordered_set<int> toRemove;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                if (stack.empty()) {
                    toRemove.insert(i);
                } else {
                    stack.pop();
                }
            } else if (s[i] == '(') {
                stack.push(i);
            }
        }
        
        while (!stack.empty()) {
            toRemove.insert(stack.top());
            stack.pop();
        }
        
        string ans;
        
        for (int i = 0; i < s.size(); i++) {
            if (!toRemove.count(i)) ans += s[i];
        }
        
        return ans;
    }
};
