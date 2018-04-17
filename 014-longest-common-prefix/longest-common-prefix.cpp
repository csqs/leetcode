// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string &quot;&quot;.
//
// Example 1:
//
//
// Input: [&quot;flower&quot;,&quot;flow&quot;,&quot;flight&quot;]
// Output: &quot;fl&quot;
//
//
// Example 2:
//
//
// Input: [&quot;dog&quot;,&quot;racecar&quot;,&quot;car&quot;]
// Output: &quot;&quot;
// Explanation: There is no common prefix among the input strings.
//
//
// Note:
//
// All given inputs are in lowercase letters a-z.
//


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.empty()) return res;
        else if(strs.size() == 1) return strs[0];
        
        for(int pos = 0; pos < strs[0].size(); pos++){
            bool out = false;
            for(auto str : strs){
                if(pos >= str.size() || str[pos] != strs[0][pos]){
                    out = true;
                    break;
                }
            }   
            if(out) break;  
            else res += strs[0].substr(pos, 1);
        }
        
        return res;
    }
};
