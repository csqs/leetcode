// Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
//
// Example 1:
//
// Input:
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// Output: 3
// Explanation: 
// The repeated subarray with maximum length is [3, 2, 1].
//
//
//
// Note:
//
// 1 <= len(A), len(B) <= 1000
// 0 <= A[i], B[i] < 100
//
//


class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int a_len = A.size() + 1, b_len = B.size() + 1;
        vector<vector<int>> dp(a_len, vector<int>(b_len));
        
        int res = 0;
        for(int i = 0; i < a_len; i++){
            for(int j = 0; j < b_len; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else{
                    if(A[i - 1] == B[j - 1]){
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        res = max(dp[i][j], res);
                    }
                }
            }
        }
        
        return res;
        
    }
};
