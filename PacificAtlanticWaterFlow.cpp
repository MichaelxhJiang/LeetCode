class Solution {
public:
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return {};
        }
        vector<vector<bool>> pacific(matrix.size(), vector<bool>(matrix[0].size()));
        vector<vector<bool>> atlantic(matrix.size(), vector<bool>(matrix[0].size()));
        queue<pair<int, int>> queue;
        //pacific shore
        for (int i = 0; i < matrix.size(); i++) {
            pacific[i][0] = true;
            queue.push({i, 0});
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            pacific[0][i] = true;
            queue.push({0, i});
        }
        bfs(queue, matrix, pacific);
        
        //atlantic shore
        for (int i = 0; i < matrix.size(); i++) {
            atlantic[i][matrix[0].size()-1] = true;
            queue.push({i, matrix[0].size()-1});
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            atlantic[matrix.size()-1][i] = true;
            queue.push({matrix.size()-1, i});
        }
        bfs(queue, matrix, atlantic);
        vector<vector<int>> ans;
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                if (atlantic[r][c] && pacific[r][c]) ans.push_back({r, c});
            }
        }
        return ans;
    }
    
    void bfs(queue<pair<int, int>>& queue, vector<vector<int>>& matrix, vector<vector<bool>>& mask) {
        while (!queue.empty()) {
            pair<int, int> coord = queue.front();
            queue.pop();
            int r = coord.first;
            int c = coord.second;
            
            if (r != 0 && !mask[r-1][c] && matrix[r][c] <= matrix[r-1][c]) {
                queue.push({r-1, c});
                mask[r-1][c] = true;
            }
            if (r != matrix.size()-1 && !mask[r+1][c] && matrix[r][c] <= matrix[r+1][c]) {
                queue.push({r+1, c});
                mask[r+1][c] = true;
            }
            if (c != 0 && !mask[r][c-1] && matrix[r][c] <= matrix[r][c-1]) {
                queue.push({r, c-1});
                mask[r][c-1] = true;
            }
            if (c != matrix[0].size()-1 && !mask[r][c+1] && matrix[r][c] <= matrix[r][c+1]) {
                queue.push({r, c+1});
                mask[r][c+1] = true;
            }
        }
    }
};
