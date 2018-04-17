// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
// Return the quotient after dividing dividend by divisor.
//
// Example 1:
//
//
// Input: dividend = 10, divisor = 3
// Output: 3
//
// Example 2:
//
//
// Input: dividend = 7, divisor = -3
// Output: -2
//
// Note:
//
//
// 	Both dividend and divisor&nbsp;will be&nbsp;32-bit&nbsp;signed integers.
// 	The divisor will never be 0.
// 	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [&minus;231, &nbsp;231 &minus; 1]. For the purpose of this problem, assume that your function returns 231 &minus; 1 when the division result&nbsp;overflows.
//
//


class Solution {
public:
    /*
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        bool neg = false;
        
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            neg = true;
        
        int res = 0;
        if(divisor == INT_MIN) return 0;
        divisor = abs(divisor);
        
        if(dividend == INT_MIN){
            if(divisor == 1) return neg ? INT_MIN : INT_MAX;
            dividend = INT_MAX - divisor + 1;
            res += 1;
        }
        
        dividend = abs(dividend);
        if(divisor == 1) return neg ? -dividend : dividend;
        
        int temp = divisor;
        while(temp <= dividend){
            if(temp > INT_MAX - divisor) break;
            temp += divisor;
            res += 1;
        }
        
        return neg ? -res : res;
    }
    */
    
    int divide(int dividend, int divisor){
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        
        bool neg = (dividend > 0 ^ divisor > 0) ? true : false;
        long div = labs(dividend);
        long dsr = labs(divisor);
        
        int res = 0;
        while(div >= dsr){
            long tmp = 1, num = dsr;
            while((num << 1) < div){
                num <<= 1;
                tmp <<= 1;
            }
            div -= num;
            res += tmp;
        }
        return neg ? -res : res;
    }
    
    /*
    int divide(int dividend, int divisor){
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        
        bool neg = ((divisor < 0) ^ (dividend < 0)) ? true : false;
        long long div = labs(dividend);
        long long dor = labs(divisor);
        
        int res = 0;
        while(div >= dor){
            long long temp = dor, multi = 1;
            while(div >= (temp << 1)){
                temp <<= 1;
                multi <<= 1;
            }
            div -= temp;
            res += multi;
        }
        
        return neg ? -res : res;
    }
    */
};
