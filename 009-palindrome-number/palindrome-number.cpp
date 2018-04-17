// Determine whether an integer is a palindrome. An integer&nbsp;is&nbsp;a&nbsp;palindrome when it&nbsp;reads the same backward as forward.
//
// Example 1:
//
//
// Input: 121
// Output: true
//
//
// Example 2:
//
//
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//
//
// Example 3:
//
//
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//
//
// Follow up:
//
// Coud you solve&nbsp;it without converting the integer to a string?
//


class Solution {
public:
    /*
    bool isPalindrome(int x) {
        if(x < 0) return false;
        else if(x == 0) return true;
        
        vector<int> tmp;
        int num = x;
        while(num > 0){
            tmp.push_back(num % 10);
            num /= 10;
        }
        
        int left = 0, right = tmp.size() - 1;
        while(right >= left){
            if(tmp[right] != tmp[left])
                return false;
            else{
                if(right == left) break;
                else if(right == left + 1) break;
                else{
                    right--;
                    left++;
                }
            }
        }
        return true;
    }
    */
    
    bool isPalindrome(int x) {
        if(x < 0 ||(x != 0 && x % 10 == 0)) return false;
        else if(x < 10) return true;
        
        int sum = 0;
        while(x > sum){
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        
        return (sum > x && sum / 10 == x) || sum == x;
    }
};
