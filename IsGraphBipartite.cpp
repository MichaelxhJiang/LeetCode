class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        unordered_map<int, bool> visited;
        
        for (int i = 0; i < graph.size(); i++) {
            if (visited.find(i) != visited.end()) continue;
            
            q.push(i);
            visited.insert({i, true});
            
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (int v : graph[cur]) {
                    if (visited.find(v) == visited.end()) {
                        visited.insert({v, !visited[cur]});
                        q.push(v);
                    }

                    if (visited[v] == visited[cur]) {
                        return false;
                    }
                }
            }
        }    
        
        
        return true;
    }
};
