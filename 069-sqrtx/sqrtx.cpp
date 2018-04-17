// Implement int sqrt(int x).
//
// Compute and return the square root of x, where&nbsp;x&nbsp;is guaranteed to be a non-negative integer.
//
// Since the return type&nbsp;is an integer, the decimal digits are truncated and only the integer part of the result&nbsp;is returned.
//
// Example 1:
//
//
// Input: 4
// Output: 2
//
//
// Example 2:
//
//
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
// &nbsp;            the decimal part is truncated, 2 is returned.
//
//


class Solution {
public:
    /*
    int mySqrt(int x) {
        int last = 0;
        for(int i = 0; i <= x; i++){
            int tmp = i * i;
            if(tmp < last) return i - 1;
            last = tmp;
            
            if(tmp > x)
                return i - 1;
            else if(tmp == x)
                return i;
        }
    }
    */
    
    int mySqrt(int x) {
        if(x <= 1) return x;
        
        int left = 0, right = x;
        while(right > left){
            int mid = (right + left) / 2;
            if((x / mid) < mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return x / right < right ? right - 1 : right;
        
    }
    
    
    /*
    int mySqrt(int x) {
        long r = x;
        while(r * r > x)
            r = (r + x/r) / 2;
        
        return r;
    }
    */
};
