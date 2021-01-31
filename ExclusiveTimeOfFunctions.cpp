class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> stack;    // function id, timestamp
        int prevTime = -1;
        for (int i = 0; i < logs.size(); i++) {
            int function;
            bool start;
            int timestamp;
            int colons = 0;
            int prev;
            for (int j = 0; j < logs[i].size(); j++) {
                if (logs[i][j] == ':') {
                    if (colons == 0) {
                        function = stoi(logs[i].substr(0, j));
                        prev = j+1;
                        colons++;
                    } else if (colons == 1) {
                        start = (logs[i].substr(prev, j - prev) == "start");
                        prev = j+1;
                        
                        timestamp = stoi(logs[i].substr(j+1));
                    }
                }
            }
            
            if (start) {
                // add time for current function
                if (!stack.empty()) {
                    int cur = stack.top();
                    ans[cur] += timestamp - prevTime;
                }
                
                // update stack
                stack.push(function);
                prevTime = timestamp;
            } else if (!start) {
                // add time for current function
                if (!stack.empty()) {
                    int cur = stack.top();
                    ans[cur] += timestamp + 1 - prevTime;
                }
                
                // update stack
                stack.pop();
                prevTime = timestamp + 1;
            }
        }
        
        return ans;
    }
};
