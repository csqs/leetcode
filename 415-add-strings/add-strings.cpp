// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
// Note:
//
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    string addStrings(string num1, string num2) {
        int len = num1.size() > num2.size() ? num1.size() : num2.size();
        string res(len, '0');
        int carry = 0;
        for(int i = num1.size() - 1, j = num2.size() - 1, k = len - 1; i >= 0 || j >= 0; i--, j--, k--){
            int n1 = i >= 0 ? num1[i] - '0' : 0;
            int n2 = j >= 0 ? num2[j] - '0' : 0;
            int tmp = n1 + n2 + carry;
            res[k] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        if(carry) return "1" + res;
        return res;
    }
};
