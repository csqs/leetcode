// Given an array nums of n integers and an integer target, find three integers in nums&nbsp;such that the sum is closest to&nbsp;target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int d = INT_MAX, res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            int l = i + 1, r = nums.size() - 1;
            while(r > l){
                int s = nums[i] + nums[l] + nums[r];
                if(s > target) r--;
                else if(s < target) l++;
                else return s;
                
                if(abs(s - target) < abs(d)){
                    d = s - target;
                    res = s;
                }
            }
        }
        return res;
    }
};
