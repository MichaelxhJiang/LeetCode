class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        // scan each cell for island
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    markIsland(i, j, grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    void markIsland(int i, int j, vector<vector<char>>& grid) {
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        
        if (i > 0) markIsland(i-1, j, grid);
        if (i < grid.size()-1) markIsland(i+1, j, grid);
        if (j > 0) markIsland(i, j-1, grid);
        if (j < grid[0].size()-1) markIsland(i, j+1, grid);
    }
};
