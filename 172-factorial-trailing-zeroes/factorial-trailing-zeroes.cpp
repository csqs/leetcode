// Given an integer n, return the number of trailing zeroes in n!.
//
// Note: Your solution should be in logarithmic time complexity.
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(long long m = 5; n / m > 0; m *= 5)
            res += n / m;
        return res;
    }
};
