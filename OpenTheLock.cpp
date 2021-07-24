class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int ans = -1;
        
        unordered_set<string> ends;
        for (string s : deadends) ends.insert(s);
        
        unordered_set<string> visited;
        visited.insert("0000");
        queue<pair<string, int>> queue;
        queue.push(make_pair("0000", 0));
        while (!queue.empty()) {
            pair node = queue.front(); queue.pop();
            string cur = node.first;
            int count = node.second;
            
            if (ends.find(cur) != ends.end()) {
                continue;
            }
            
            if (cur == target) {
                return count;
            }
            
            for (int i = 0; i < 4; i++) {
                string next = "";
                for (int j = 0; j < i; j++) next += cur[j];
                if (cur[i] < '9') next += cur[i]+1;
                else next += '0';
                for (int j = i+1; j < 4; j++) next += cur[j];
                
                if (visited.find(next) == visited.end()) {
                    queue.push(make_pair(next, count+1));
                    visited.insert(next);
                }
                
                next = "";
                for (int j = 0; j < i; j++) next += cur[j];
                if (cur[i] > '0') next += cur[i]-1;
                else next += '9';
                for (int j = i+1; j < 4; j++) next += cur[j];
                
                if (visited.find(next) == visited.end()) {
                    queue.push(make_pair(next, count+1));
                    visited.insert(next);
                }
            }
        }
        
        return -1;
    }
};
