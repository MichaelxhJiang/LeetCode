class Solution {
public:
    
    map<pair<int, int>, vector<int>> memo;
    
    int compute(int a, string op, int b) {
        if (op == "+") {
            return a + b;
        } else if (op == "-") {
            return a - b;
        } else {
            return a * b;
        }
    }
    
    bool isOp(string s) {
        if (s == "+" || s == "-" || s == "*") {
            return true;
        }
        
        return false;
    }
    
    vector<int> recurse(const vector<string> & sequence, int start, int end) {
        vector<int> ans;
        
        //check memo
        if (memo.find({start, end}) != memo.end()) {
            return memo[{start, end}];
        }
        
        //base case is start = end which is just a number
        if (start == end) {
            ans.push_back(stoi(sequence[start]));
            return ans;
        }
        
        //divide and conquer to try every combination of parentheses
        for (int i = start + 1; i < end; i++) {
            if (isOp(sequence[i])) {
                vector<int> leftResult = recurse(sequence, start, i - 1);
                vector<int> rightResult = recurse(sequence, i + 1, end);
                
                for (int left : leftResult) {
                    for (int right : rightResult) {
                        ans.push_back(compute(left, sequence[i], right));
                    }
                }
            }
        }
        
        memo[{start, end}] = ans;
        
        return ans;
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<string> sequence;
        string str = "";

        for (auto s : input) {
            if (s == '+' || s == '-' || s == '*') {
                sequence.push_back(str);
                str = "";
                sequence.push_back(string(1, s));
            } else {
                str += s;   
            }
        }
        
        if (str != "") sequence.push_back(str);
        
        vector<int> ans = recurse(sequence, 0, sequence.size() - 1);
        
        return ans;
    }
};
