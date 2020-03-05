class Solution {
public:
    int memo[1000][1000];
    int findMin(vector<vector<int>>& triangle, int row, int column) {
        if (memo[row][column]) return memo[row][column];
        
        if (row == triangle.size() -1) return triangle[row][column];
        
        //possibilities are row and row + 1
        int ans = min(triangle[row][column] + findMin(triangle, row+1, column), triangle[row][column] + findMin(triangle, row+1, column + 1));
        memo[row][column] = ans;
        return ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return findMin(triangle, 0, 0);
    }
};
