// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: &quot;babad&quot;
// Output: &quot;bab&quot;
// Note: &quot;aba&quot; is also a valid answer.
//
//
// Example 2:
//
//
// Input: &quot;cbbd&quot;
// Output: &quot;bb&quot;
//
//


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return s;
        
        int start = 0, end =0;
        for(int i = 0; i + 1 < s.size(); i++){
            int left = 0, right = 0;
            if(s[i] == s[i + 1]){
                left = i;
                right = i + 1;
                while(left >= 0 && right < s.size() && s[left] == s[right]){
                    left--;
                    right++;
                }
                if(right - left - 2 > end - start){
                    start = left + 1;
                    end = right - 1;
                }
            }
            
            if(i - 1 >= 0 && s[i - 1] == s[i + 1]){
                left = i - 1;
                right = i + 1;
                while(left >= 0 && right < s.size() && s[left] == s[right]){
                    left--;
                    right++;
                }
                if(right - left - 2 > end - start){
                    start = left + 1;
                    end = right - 1;
                }
            }
            
        }
            
        return s.substr(start, end - start + 1);
    }
};
