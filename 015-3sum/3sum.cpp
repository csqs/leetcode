// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i + 2 < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while(r > l){
                int s = nums[i] + nums[l] + nums[r];
                if(s > 0) r--;
                else if(s < 0) l++;
                else{
                    vector<int> tmp = {nums[i], nums[l], nums[r]};
                    res.push_back(tmp);
                    
                    while(nums[r - 1] == nums[r]) r--;
                    while(nums[l + 1] == nums[l]) l++;
                    r--;
                    l++;
                }
            }
        }
        
        return res;
    }
};
