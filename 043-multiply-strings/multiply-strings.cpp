// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
//
// Input: num1 = &quot;2&quot;, num2 = &quot;3&quot;
// Output: &quot;6&quot;
//
// Example 2:
//
//
// Input: num1 = &quot;123&quot;, num2 = &quot;456&quot;
// Output: &quot;56088&quot;
//
//
// Note:
//
//
// 	The length of both num1 and num2 is &lt; 110.
// 	Both num1 and num2 contain&nbsp;only digits 0-9.
// 	Both num1 and num2&nbsp;do not contain any leading zero, except the number 0 itself.
// 	You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    /*
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        string res = "0";
        for(int i = num2.size() - 1; i >= 0; i--){
            string temp = multione(num1, num2[i]);
            for(int j = num2.size() - 1; j > i; j --){
                temp += "0";
            }
            res = add(res, temp);
        }
        return res;
    }
    
    string multione(string num1, char num2){
        int mul = num2 - '0';
        int extra = 0;
        for(int i = num1.size() - 1; i >= 0; i--){
            int temp = (num1[i] - '0') * mul + extra;
            extra = temp / 10;
            num1[i] = '0' + temp % 10;
        }
        if(extra){
            string first = " ";
            first[0] = '0' + extra;
            return first + num1;
        }
        return num1;
    }
    
    string add(string num1, string num2){
        int extra = 0;
        for(int i = num1.size() - 1, j = num2.size() - 1; i >= 0 && j >=0; i--, j--){
            int temp = (num1[i] - '0') + (num2[j] - '0') + extra;
            extra = temp / 10;
            temp %= 10;
            num2[j] = '0' + temp;
            if(i == 0 && extra){
                while(extra && j > 0){
                    j--;
                    int one_temp = (num2[j] - '0') + extra;
                    extra = one_temp / 10;
                    num2[j] = '0' + one_temp % 10;
                }
            }
        }
        if(extra) return "1" + num2;
        else return num2;
    }
    */
    
    string multiply(string num1, string num2){
        if(num1 == "0" || num2 == "0") return "0";
        
        string res(num1.size() + num2.size(), '0');
        for(int i = num1.size() - 1; i >= 0; i--){
            int carry = 0;
            for(int j = num2.size() - 1; j >= 0; j--){
                int tmp = res[i + j + 1] - '0' + carry + (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            res[i] += carry;
        }
        
        size_t start = res.find_first_not_of("0");
        if(start != string::npos)
            return res.substr(start);
        return res;
    }
    
    /*
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        string res(num1.size() + num2.size(), '0');
        for(int i = num1.size() - 1; i >= 0; i--){
            int carry = 0;
            for(int j = num2.size() - 1; j >= 0; j --){
                int tmp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                res[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            res[i] += carry;
        }
        size_t start =  res.find_first_not_of("0");
        if(start != string::npos){
            return res.substr(start);
        }
        return res;
    }
    */
};
