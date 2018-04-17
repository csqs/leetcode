// Given an array nums, we call (i, j) an important reverse pair if i &lt; j and nums[i] &gt; 2*nums[j].
//
// You need to return the number of important reverse pairs in the given array.
//
// Example1:
//
// Input: [1,3,2,3,1]
// Output: 2
//
//
// Example2:
//
// Input: [2,4,3,5,1]
// Output: 3
//
//
// Note:
//
// The length of the given array will not exceed 50,000.
// All the numbers in the input array are in the range of 32-bit integer.
//
//


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        vector<int> copy(nums);
        return merge(nums, copy, 0, nums.size() - 1);
    }
    
    int merge(vector<int>& nums, vector<int>& copy, int left, int right){
        if(left >= right) return 0;
        
        int mid = (left + right) / 2;
        int left_res = merge(nums, copy, left, mid);
        int right_res = merge(nums, copy, mid + 1, right);
        
        int merge_res = 0, copy_index = left, left_index = left, right_index = mid + 1, last_start = left;
        
        while(left_index <= mid or right_index <= right){
            if(right_index == right + 1 || (left_index <= mid and long(nums[left_index]) < long(nums[right_index]))){
                copy[copy_index++] = nums[left_index++];
            }
            else{
                
                for(; last_start <= mid; last_start++){
                    if(long(nums[last_start]) > 2L * long(nums[right_index])){
                        merge_res += mid - last_start + 1;
                        //last_start = i;
                        break;
                    }
                }
                
                copy[copy_index++] = nums[right_index++];
            }
        }
        for(int i = left; i <= right; i++)
            nums[i] = copy[i];
        
        return (left_res + right_res + merge_res);
    }
};
