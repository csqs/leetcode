//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n <= 0) return res;
        dp(res, "", n, 0);
        return res;
    }
    
    void dp(vector<string> &res, string cur, int left, int right){
        if(left == 0 && right == 0){
            res.push_back(cur);
            return;
        }
        if(left > 0) dp(res, cur + "(", left - 1, right + 1);
        if(right > 0) dp(res, cur + ")", left, right - 1);
    }
};
