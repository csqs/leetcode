//
// You are given an integer array nums and you have to return a new counts array.
// The counts array has the property where counts[i] is 
// the number of smaller elements to the right of nums[i].
//
//
// Example:
//
//
// Given nums = [5, 2, 6, 1]
//
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
//
//
//
// Return the array [2, 1, 1, 0].
//


class Solution {
public:
    /*
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        
        for(auto n : nums)
            res.push_back(0);
        mergeCal(nums, res, 0, nums.size() - 1);
        return res;
    }
    
    void mergeCal(vector<int> &nums, vector<int> &res, int left, int right){
        if(left >= right){
            res[right] = 0;
            return;
        }
        
        int mid = (left + right) / 2;
        mergeCal(nums, res, left, mid);
        mergeCal(nums, res, mid + 1, right);
        
        for(int i = left; i <= mid; i++){
            int res_temp = 0;
            for(int j = mid + 1; j <= right; j++){
                if(nums[j] < nums[i])
                    res_temp++;
            }
            res[i] += res_temp;
        }
    }
    */
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        
        vector<int> pos, copy;
        for(int i = 0; i < nums.size(); i++){
            pos.push_back(i);
            res.push_back(0);
            copy.push_back(i);
        }
        
        mergeCal(nums, copy, pos, res, 0, nums.size() - 1);
        return res;
    }
    
    void mergeCal(vector<int> &nums, vector<int> &copy, vector<int> &pos, vector<int> &res, int left, int right){
        if(left >= right) return;
        
        int mid = (left + right) / 2;
        mergeCal(nums, copy, pos, res, left, mid);
        mergeCal(nums, copy, pos, res, mid + 1, right);
        
        int copy_index = left, left_index = left, right_index = mid + 1;
        while(left_index <= mid || right_index <= right){
            if(right_index == right + 1 || (left_index <= mid && nums[pos[left_index]] <= nums[pos[right_index]])){
                res[pos[left_index]] += right_index - mid - 1;
                copy[copy_index++] = pos[left_index++];
            }
            else{
                copy[copy_index++] = pos[right_index++];
            }
        }
        /*
        while(right_index <= right){
            copy[copy_index++] = pos[right_index++];
        }           
        while(left_index <= mid){
            if(nums[pos[left_index]] < nums[pos[right_index]]){
                res[pos[left_index]] += right_index - mid - 1;
                copy[copy_index++] = pos[left_index++];
            }
        }
        */
        for(int i = left; i <= right; i++)
            pos[i] = copy[i];
        
    }
};
