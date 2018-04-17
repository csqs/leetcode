//
//     Given an integer, write a function to determine if it is a power of three.
//
//
//     Follow up:
//     Could you do it without using any loop / recursion?
//
//
// Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int max = pow(3, int(log(INT_MAX) / log(3)));
        return max % n == 0;
    }
};
