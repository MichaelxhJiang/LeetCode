class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> inDegree;
        string ans = "";
        for (string word : words) {
            for (char c : word) {
                if (adjList.find(c) == adjList.end()) {
                    adjList.insert({c, vector<char>()});
                }
                if (inDegree.find(c) == inDegree.end()) {
                    inDegree.insert({c, 0});
                }
            }
        }
        
        for (int i = 0; i < words.size()-1; i++) {
            int index = 0;
            while (index < words[i].length() && index < words[i+1].length() && words[i][index] == words[i+1][index]) index++;
            
            if (index >= words[i].length() || index >= words[i+1].length()) {
                if (words[i+1].length() < words[i].length()) return "";
                continue;
            }
            
            adjList[words[i][index]].push_back(words[i+1][index]);
            inDegree[words[i+1][index]]++;
        }
        
        queue<char> q;
        for (pair<char, int> deg : inDegree) {
            if (deg.second == 0) {
                ans += deg.first;
                q.push(deg.first);
            }
        }
        while(!q.empty()) {
            char node = q.front();
            q.pop();
            
            for (char v : adjList[node]) {
                if (--inDegree[v] == 0) {
                    ans += v;
                    q.push(v);
                }
            }
        }
        
        return (ans.length() == inDegree.size()) ? ans : "";
    }
};
