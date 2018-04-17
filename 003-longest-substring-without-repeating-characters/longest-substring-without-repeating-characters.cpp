// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
//
// Given "abcabcbb", the answer is "abc", which the length is 3.
//
// Given "bbbbb", the answer is "b", with the length of 1.
//
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    /*
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int start = 0, end = 0, res = 0;
        while(start < s.size()){
            map<char, int> m;
            end = start;
            while(end < s.size()){
                if(m.find(s[end]) != m.end()){
                    break;
                }
                else{
                    m[s[end]] = end;
                    end++;
                }
            }
            res = end - start > res ? end - start : res; 
            if(m.find(s[end]) != m.end())
                start = m[s[end]];
            start++;
        }
        return res;
    }
    */
    int lengthOfLongestSubstring(string s){
        vector<int> charMap(256, - 1);
        int res = 0, start = -1;
        for(int i = 0; i < s.size(); i++){
            if(charMap[s[i]] > start)
                start = charMap[s[i]];
            charMap[s[i]] = i;
            res = max(res, i - start);
        }
        return res;
    }
};
