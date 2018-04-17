// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or&nbsp;0.
//
// Example 1:
//
//
// Input: a = &quot;11&quot;, b = &quot;1&quot;
// Output: &quot;100&quot;
//
// Example 2:
//
//
// Input: a = &quot;1010&quot;, b = &quot;1011&quot;
// Output: &quot;10101&quot;
//


class Solution {
public:
    string addBinary(string a, string b) {
        string res = b.size() > a.size() ? b : a;
        string base = b.size() > a.size() ? a : b;
        
        int extra = 0;
        for(int i = base.size() - 1, j = res.size() - 1; j >= 0; i--, j--){
            int b_num = i >= 0 ? (base[i] - '0') : 0;
            int res_num = res[j] - '0';
            
            if(b_num + extra == 0)
                continue;
            else{
                res_num += b_num + extra;
                if(res_num >= 2){
                    extra = 1;
                    res_num -= 2;
                }
                else{
                    extra = 0;
                }

                res[j] = res_num + '0';
            }
        }
        
        if(extra) return "1" + res;
        return res;        
    }
};
