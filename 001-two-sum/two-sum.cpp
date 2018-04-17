// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// Example:
//
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//
//
// &nbsp;
//


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int key = nums[i];
            int next_key = target - key;
            if(nums_map.find(next_key) != nums_map.end()){
                res.push_back(i);
                res.push_back(nums_map[next_key]);
                return res;
            }
            nums_map[key] = i;
        }
        return res;
    }
};
