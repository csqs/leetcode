//
// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum &ge; s. If there isn't one, return 0 instead.
//
//
// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.
//
//
// click to show more practice.
//
// More practice:
//
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
//
//
// Credits:Special thanks to @Freezen for adding this problem and creating all test cases.


class Solution {
public:
    /*
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len));
        
        int sum = 0;
        for(auto n : nums)
            sum += n;
        if(sum < s)
            return 0;
        
        int res = len;
        for(int i = 0; i < len; i++){
            for(int j = i; j < len; j++){
                if(i == j)
                    dp[i][j] = nums[j];
                else
                    dp[i][j] = nums[j] + dp[i][j - 1];
                
                if(dp[i][j] >= s){
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res;
    }
    */
    
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, sum = 0, res = INT_MAX;
        while(right < n){
            do sum += nums[right++];
            while (right < n && sum < s);
            /*
            while(right < n && sum < s){
                sum += nums[right];
                right++;
            }
            */
            while(left < right && sum - nums[left] >= s){
                sum -= nums[left];
                left++;
            }
            if(sum >= s)
                res = min(res, right - left);
        }       
        
        return res == INT_MAX ? 0 : res;
    }
    
    
};
