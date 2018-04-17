//  Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
// Example:
//
// nums = [1, 2, 3]
// target = 4
//
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
//
// Note that different sequences are counted as different combinations.
//
// Therefore the output is 7.
//
//
//
// Follow up:
// What if negative numbers are allowed in the given array?
// How does it change the problem?
// What limitation we need to add to the question to allow negative numbers? 
//
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases.


class Solution {
/*
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        recurFind(nums, target, res);
        return res;
    }
    
    int recurFind(vector<int>& nums, int target, int &res){
        if(target == 0){
            return 1;
        }
        
        if(history.find(target) != history.end())
            return history[target];
        else{
            for(int i = 0; i < nums.size() && target >= nums[i]; i++){
                res += recurFind(nums, target - nums[i], res);
            }
        }
        
        if(history.find(target) == history.end() && res > 0)
            history[target] = res;
        
        
        for(int i = 0; i < nums.size() && target >= nums[i]; i++){
            int key = target - nums[i];
            int val;
            if(history.find(key) == history.end()){
                val = recurFind(nums, target - nums[i], res);
                if(val != 0) history[key] = val;
            }
            else val = history[key];
            
            res += val;
        }
        
        return 0;
    }
private:
    map<int, int> history;
*/
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= target; i++){
            for(auto n : nums){
                if(i < n) break;
                dp[i] += dp[i - n];
            }
        }
        
        return dp.back();
    }
    
};

