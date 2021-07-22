class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefixArea = vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1));
        prefixArea[0][0] = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                prefixArea[i+1][j+1] = prefixArea[i][j+1]+prefixArea[i+1][j]+matrix[i][j]-prefixArea[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixArea[row2+1][col2+1]-prefixArea[row1][col2+1]-prefixArea[row2+1][col1]+prefixArea[row1][col1];
    }
private:
    vector<vector<int>> prefixArea;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
