//
// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//
//
//  Example 1:
// Input:  k = 3,  n = 7
// Output: 
//
// [[1,2,4]]
//
//
//  Example 2:
// Input:  k = 3,  n = 9
// Output: 
//
// [[1,2,6], [1,3,5], [2,3,4]]
//
//
//
// Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        recurFind(k, n, res, path, 1);
        return res;        
    }
    
    void recurFind(int k, int n, vector<vector<int>> &res, vector<int> &path, int begin){
        if(k == 0 && n == 0){
            res.push_back(path);
            return;
        }
        
        for(int i = begin; i <= 9 && n >= i && k > 0; i++){
            path.push_back(i);
            recurFind(k - 1, n - i, res, path, i + 1);
            path.pop_back();
        }
        
    }
};
