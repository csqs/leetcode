// A robot is located at the top-left corner of a m x n grid (marked &#39;Start&#39; in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked &#39;Finish&#39; in the diagram below).
//
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// Note: m and n will be at most 100.
//
// Example 1:
//
//
// Input:
// [
// &nbsp; [0,0,0],
// &nbsp; [0,1,0],
// &nbsp; [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -&gt; Right -&gt; Down -&gt; Down
// 2. Down -&gt; Down -&gt; Right -&gt; Right
//
//


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
        
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<int> cur(col, 0);
        for(int i = 0; i < col; i++){
            if(obstacleGrid[0][i])
                break;
            cur[i] = 1;
        }
        
        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++){
                if(obstacleGrid[i][j]) cur[j] = 0;
                else cur[j] = j == 0? cur[j] : cur[j] + cur[j - 1];
            }
        }
        
        return cur[col - 1];
    }
};
