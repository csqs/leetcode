// Implement pow(x, n), which calculates&nbsp;x raised to the power n (xn).
//
// Example 1:
//
//
// Input: 2.00000, 10
// Output: 1024.00000
//
//
// Example 2:
//
//
// Input: 2.10000, 3
// Output: 9.26100
//
//
// Example 3:
//
//
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
//
//
// Note:
//
//
// 	-100.0 &lt; x &lt; 100.0
// 	n is a 32-bit signed integer, within the range&nbsp;[&minus;231,&nbsp;231&nbsp;&minus; 1]
//
//


class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        
        bool neg = n < 0 ? true : false;
        long nn = labs(n);
        double res = 1.0;
        
        long num = nn;
        double tmp = x;
        while(num){
            if(num & 0x1){
                res *= tmp;
            }
            tmp *= tmp;
            num >>= 1;
        }
        
        return neg ? 1 / res : res;
    }
};
