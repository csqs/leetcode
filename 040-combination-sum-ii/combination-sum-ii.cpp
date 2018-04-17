// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates&nbsp;where the candidate numbers sums to target.
//
// Each number in candidates&nbsp;may only be used once in the combination.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates =&nbsp;[10,1,2,7,6,1,5], target =&nbsp;8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// Example 2:
//
//
// Input: candidates =&nbsp;[2,5,2,1,2], target =&nbsp;5,
// A solution set is:
// [
// &nbsp; [1,2,2],
// &nbsp; [5]
// ]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        recurFind(candidates, target, res, path, 0);
        return res;
    }
    /*
    void recurFind(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> &path, int begin){
        if(target == 0){
            if(find(res.begin(), res.end(), path) == res.end())
                res.push_back(path);
            return;
        }
        
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++){
            path.push_back(candidates[i]);
            recurFind(candidates, target - candidates[i], res, path, i + 1);
            path.pop_back();
        }
    }
    */
    
    void recurFind(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int> &path, int begin){
        if(target == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++){
            if(i == begin || candidates[i] != candidates[i - 1]){
                path.push_back(candidates[i]);
                recurFind(candidates, target - candidates[i], res, path, i + 1);
                path.pop_back();
            }
        }
    }
};
