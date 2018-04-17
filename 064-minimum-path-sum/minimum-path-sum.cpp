// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example:
//
//
// Input:
// [
// &nbsp; [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1&rarr;3&rarr;1&rarr;1&rarr;1 minimizes the sum.
//
//


class Solution {
public:
    /*
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        return dp(grid, grid.size() - 1, grid[0].size() - 1);
    }
    
    int dp(vector<vector<int>> &grid, int row, int col){
        if(row == 0 && col == 0) return grid[0][0];
        else if(row == 0) return grid[row][col] + dp(grid, row, col - 1);
        else if(col == 0) return grid[row][col] + dp(grid, row - 1, col);
        else return grid[row][col] + min(dp(grid, row - 1, col), dp(grid, row, col - 1));
    }
    */
    
    /*
    int minPathSum(vector<vector<int>>& grid){
        if(grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size(); 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;
                int left = j == 0 ? INT_MAX : grid[i][j - 1];
                int up = i == 0 ? INT_MAX : grid[i - 1][j];
                grid[i][j] += min(left, up);
            }    
        }
        return grid[n - 1][m - 1];
    }
    */
    
    int minPathSum(vector<vector<int>>& grid){
        if(grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size(); 
        vector<int> cur(m, 0);
        for(int i = 0; i < m; i++){
            cur[i] = i == 0 ? grid[0][i] : cur[i - 1] + grid[0][i];
        }
        for(int i = 1; i < n; i++){
            cur[0] += grid[i][0];
            for(int j = 1; j < m; j++){
                cur[j] = grid[i][j] + min(cur[j - 1], cur[j]);
            }    
        }
        return cur[m - 1];
    }
};
