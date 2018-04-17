//
// Write a program to find the n-th ugly number.
//
//
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
//
//
// Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    /*
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        
        set<long> nums;
        nums.insert(1);
        int past = 0;
        for(int i = 0; i < n; i++){
            set<long>::iterator first = nums.begin();
            if(past + 1 == n)
                return *(nums.begin());
            
            long tmp = *first * 2;
            if(nums.find(tmp) == nums.end()){
                nums.insert(tmp);
            }
            tmp = *first * 3;
            if(nums.find(tmp) == nums.end()){
                nums.insert(tmp);
            }
            tmp = *first * 5;
            if(nums.find(tmp) == nums.end()){
                nums.insert(tmp);
            }
            
            nums.erase(nums.begin());
            past += 1;
        }
        
        return 0;
    }
    */
    int nthUglyNumber(int n){
        if(n <= 0) return 0;
        
        vector<int> res(n);
        res[0] = 1;
        int mul2 = 0, mul3 = 0, mul5 = 0;
        for(int i = 1; i < n; i++){
            res[i] = min(min(res[mul2] * 2, res[mul3] * 3), res[mul5] * 5);
            if(res[i] == res[mul2] * 2) mul2++;
            if(res[i] == res[mul3] * 3) mul3++;
            if(res[i] == res[mul5] * 5) mul5++;
        }
        return res[n - 1];
    }
};
