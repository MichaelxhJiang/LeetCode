class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int i = 0; i < nums.size(); i++) {
            numSet.insert(nums[i]);
        }
        
        int longestSeq = 0;
        for (int num : numSet) {
            // is this a start of a new sequence
            if (numSet.find(num-1) == numSet.end()) {
                int curNum = num;
                int curSeq = 1;
                
                // loop to end of this sequence (note this loop iterates over every element only
                // once throughout the entire runtime of the algorithm since we only do this if
                // we encounter a new sequence) So total runtime is O(N)
                while (numSet.find(curNum+1) != numSet.end()) {
                    curNum++;
                    curSeq++;
                }
                longestSeq = max(curSeq, longestSeq);
            }
        }
        
        return longestSeq;
    }
    
//     int longestConsecutive(vector<int>& nums) {
//         if (nums.empty()) return 0;
        
//         unordered_map<int, int> adjList;
//         unordered_map<int, int> dp;
//         for (int i = 0; i < nums.size(); i++) {
//             dp.insert({nums[i], 1});
//         }
        
//         for (int i = 0; i < nums.size(); i++) {
//             if (dp.find(nums[i]-1) != dp.end()) {
//                 adjList.insert({nums[i]-1, nums[i]});
//             }
//             if (dp.find(nums[i]+1) != dp.end()) {
//                 adjList.insert({nums[i], nums[i]+1});
//             }
//         }
        
//         unordered_set<int> visited;
//         for (int i = 0; i < nums.size(); i++) {
//             if (visited.find(nums[i]) == visited.end()) {
//                 dfs(nums[i], adjList, visited, dp);
//             }
//         }
        
//         int ans = 1;
//         for (int i = 0; i < nums.size(); i++) {
//             ans = max(ans, dp[nums[i]]);
//         }
        
//         return ans;
//     }
    
//     void dfs(int node, unordered_map<int, int>& adjList, unordered_set<int>& visited, unordered_map<int, int>& dp) {
//         visited.insert(node);
//         if (adjList.find(node) != adjList.end()) {
//             int u = adjList[node];
//             if (visited.find(u) == visited.end()) {
//                 dfs(u, adjList, visited, dp);
//             }
//             dp[node] = max(dp[node], 1 + dp[u]);
//         }
        
//     }
};
