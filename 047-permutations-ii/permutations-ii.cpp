// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())){
            res.push_back(nums);
        }
        
        return res;
    }
};
