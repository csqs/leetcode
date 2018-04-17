// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates&nbsp;where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates&nbsp;unlimited number of times.
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
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
// &nbsp; [2,2,2,2],
// &nbsp; [2,3,3],
// &nbsp; [3,5]
// ]
//
//


class Solution {
public:
    /*
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        recurFind(candidates, target, res, path);
        return res;
    }
    
    void recurFind(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &path){
        if(target == 0){
            sort(path.begin(), path.end());
            if(find(res.begin(), res.end(), path) == res.end())
                res.push_back(path);
            return;
        }
        else if(target < 0){
            return;
        }
        
        for(auto n : candidates){
            vector<int> newPath = path;
            newPath.push_back(n);
            path.push_back(n);
            recurFind(candidates, target - n, res, newPath);
        }
    }
    */
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        recurFind(candidates, target, res, path, 0);
        return res;
    }
    
    void recurFind(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &path, int begin){
        if(target == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++){
            path.push_back(candidates[i]);
            recurFind(candidates, target - candidates[i], res, path, i);
            path.pop_back();
        }
    }
    
};
