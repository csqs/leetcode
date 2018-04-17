// A robot is located at the top-left corner of a m x n grid (marked &#39;Start&#39; in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked &#39;Finish&#39; in the diagram below).
//
// How many possible unique paths are there?
//
//
// Above is a 7 x 3 grid. How many possible unique paths are there?
//
// Note: m and n will be at most 100.
//
// Example 1:
//
//
// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -&gt; Right -&gt; Down
// 2. Right -&gt; Down -&gt; Right
// 3. Down -&gt; Right -&gt; Right
//
//
// Example 2:
//
//
// Input: m = 7, n = 3
// Output: 28
//


class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0) return 0;
        else if(m == 1 || n == 1) return 1;
        
        long long c_mn = 1, c_n = 1;
        if(n > m) swap(n, m);
        for(int i = m + n - 2; i > m - 1; i--)
            c_mn *= i;
        for(int i = n - 1; i > 0; i--)
            c_n *= i;
        return c_mn / c_n;
    }
};
