// Given a 32-bit signed integer, reverse digits of an integer.
//
// Example 1:
//
//
// Input: 123
// Output: 321
//
//
// Example 2:
//
//
// Input: -123
// Output: -321
//
//
// Example 3:
//
//
// Input: 120
// Output: 21
//
//
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [&minus;231,&nbsp; 231&nbsp;&minus; 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//


class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0 ? true : false;
        long num = labs(x);
        
        long res = 0;
        while(num){
            int tmp = num % 10;
            num /= 10;
            res *= 10;
            res += tmp;
        }
        
        if((neg && res + INT_MIN > 0) || (!neg && res > INT_MAX)) return 0;
        else return neg ? int(-res) : int(res); 
    }
};
