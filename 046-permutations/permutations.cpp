// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


class Solution {
public:
    /*
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        vector<int> path;
        dfs(res, nums, path, nums.size(), 0);
        return res;
    }
    
    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &path, int remain, int begin){
        if(remain == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(find(path.begin(), path.end(), nums[i]) != path.end()) continue;
            
            path.push_back(nums[i]);
            dfs(res, nums, path, remain - 1, i);
            path.pop_back();
        }
    }
    */
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        vector<int> path;
        swapNum(res, nums, 0);
        return res;
    }
    
    void swapNum(vector<vector<int>> &res, vector<int> &nums, int begin){
        if(begin >= nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i = begin; i < nums.size(); i++){
            swap(nums[begin], nums[i]);
            swapNum(res, nums, begin + 1);
            swap(nums[i], nums[begin]);
        }
    }
};
