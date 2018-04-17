// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm&#39;s runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        
        int left = 0, right = nums.size() - 1;
        while(right >= left){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(left >= nums.size() || nums[left] != target) return res;
        res[0] = left;
        
        left = 0, right = nums.size() - 1;
        while(right >= left){
            int mid = (left + right) / 2;
            if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        res[1] = right;
        return res;
    }
    
    /*
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        
        int left = 0, right = nums.size() - 1;
        while(right >= left){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        if(left >= nums.size() || nums[left] != target) return res;
        res[0] = left;
        
        left = 0, right = nums.size() - 1;
        while(right >= left){
            int mid = left + (right - left) / 2;
            if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        res[1] = right;
        return res; 
    }
    */
};
