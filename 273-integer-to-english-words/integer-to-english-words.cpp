//
// Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
//
//
// For example,
//
// 123 -> "One Hundred Twenty Three"
// 12345 -> "Twelve Thousand Three Hundred Forty Five"
// 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


class Solution {
public:
    /*
    string numberToWords(int num) {
        vector<string> bits = {"Thousand", "Million", "Billion", "Trillion"};
        vector<string> nums = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> twos = {"Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        string res = "";
        if(num == 0) return "Zero";
        int bit_num = 0;
        int signal = 0;
        int left = 0, mid = 0, right = 0;
        while(n){
            int last_bit = n % 10;
            n /= 10;
            if(signal % 3 == 0) right = last_bit;
            else if(signal % 3 == 1) mid = last_bit;
            else if(signal % 3 == 2){
                left = last_bit;
                string temp = "";
                if(right > 0 && mid > 1){
                    temp = twos[mid - 1] + " " + nums[right - 1];
                }
                else if(right == 0 && mid > 1){
                    
                }
            }
            signal++;
            
        }
    }
    */
    
    string numberToWords(int num){
        if(num == 0) return "Zero";
        return recurStr(num).substr(1);
    }
    
    string recurStr(int n){
        if(n >= 1e9) return recurStr(n / 1000000000) + " Billion" + recurStr(n - 1000000000 * (n / 1000000000));
        else if(n >= 1e6) return recurStr(n / 1000000) + " Million" + recurStr(n - 1000000 * (n / 1000000));
        else if(n >= 1e3) return recurStr(n / 1000) + " Thousand" + recurStr(n - 1000 * (n / 1000));
        else if(n >= 1e2) return recurStr(n / 100) + " Hundred" + recurStr(n - 100 * (n / 100));
        else if(n >= 20) return string(" ") + twos[n / 10 - 2] + recurStr(n - 10 * (n / 10));
        else if(n >= 1) return string(" ") + nums[n - 1];
        else return "";
    }
    
private:
    vector<string> nums = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> twos = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
};
