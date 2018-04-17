//
// Given an integer, write a function to determine if it is a power of two.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        else return !(n & (n - 1));
    }
};
