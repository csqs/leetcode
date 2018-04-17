//
// Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
//
//
// Example1:
//
// a = 2
// b = [3]
//
// Result: 8
//
//
//
// Example2:
//
// a = 2
// b = [1,0]
//
// Result: 1024
//
//
//
// Credits:Special thanks to @Stomach_ache for adding this problem and creating all test cases.


class Solution {
public:
    // ab % k = (a % k)(b % k) % k
    const int base = 1337;
    int powmod(int a, int k){
        a %= base;
        int res = 1;
        for(int i = 0; i < k; i++){
            res = (res * a) % base;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last) % base;
    }
};
