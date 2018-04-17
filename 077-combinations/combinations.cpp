//
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//
// For example,
// If n = 4 and k = 2, a solution is:
//
//
//
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n < 1 || k < 1) return res;
        
        vector<int> nums;
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        vector<int> path;
        combineNum(res, nums, path, k, 0);
        return res;
    }
    
    void combineNum(vector<vector<int>> &res, vector<int> &nums, vector<int> &path, int remain, int begin){
        if(remain == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = begin; i < nums.size(); i++){
            path.push_back(nums[i]);
            combineNum(res, nums, path, remain - 1, i + 1);
            path.pop_back();
        }
    }
};
