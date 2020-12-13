class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);
        for (vector<int> prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            for (int v : adj[i]) {
                inDegree[v]++;
            }
        }
        
        queue<int> queue;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                queue.push(i);
            }
        }
        
        int count = 0;
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            
            for (int v : adj[u]) {
                if (--inDegree[v] == 0) {
                    queue.push(v);
                }
            }
            
            count++;
        }
        
        if (count != numCourses) return false;
        else return true;
    }
};
