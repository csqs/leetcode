// Given a non negative integer number num. For every numbers i in the range 0 &le; i &le; num calculate the number of 1's in their binary representation and return them as an array.
//
//
// Example:
// For num = 5 you should return [0,1,1,2,1,2].
//
//
// Follow up:
//
// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount  in c++ or in any other language.
//
//
//
// Credits:Special thanks to @ syedee  for adding this problem and creating all test cases.


class Solution {
public:
    /*
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i = 0; i <= num; i++){
            int t = 0, n = i;
            while(n){
                n = n & (n - 1);
                t += 1;
            }
            res.push_back(t);
        }
        return res;
    }
    */
    
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for(int i = 1; i <= num; i++){
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
};
