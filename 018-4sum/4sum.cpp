// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 && j < nums.size() && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = nums.size() - 1;
                while(r > l){
                    int s = nums[i] + nums[j] + nums[l] + nums[r];
                    if(s > target) r--;
                    else if(s < target) l++;
                    else{
                        vector<int> tmp = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(tmp);
                        while(nums[r - 1] == nums[r]) r--;
                        r--;
                        while(nums[l + 1] == nums[l]) l++;
                        l++;
                    }
                }
            }    
        }
        return res;
    }
};
