// Given two strings s and t, determine if they are isomorphic.
//
// Two strings are isomorphic if the characters in s can be replaced to get t.
//
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
// For example,
// Given "egg", "add", return true.
//
// Given "foo", "bar", return false.
//
// Given "paper", "title", return true.
//
// Note:
// You may assume both s and t have the same length.


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char s_map[128] = {0};
        char t_map[128] = {0};
        for(int i = 0; i < s.size(); i++){
            if(s_map[s[i]] != t_map[t[i]])
                return false;
            s_map[s[i]] = i + 1;
            t_map[t[i]] = i + 1;
        }
        return true;
    }
    
    /*
    bool isIsomorphic(string s, string t) {
        string ps = returnPattern(s);
        string pt = returnPattern(t);
        
        return ps == pt;
    }
    
    string returnPattern(string s){
        char index = '1';
        unordered_map<char, char> cmap;
        string res; 
        for(int i = 0; i < s.size(); i++){
            if(cmap.find(s[i]) != cmap.end()){
                res += cmap[s[i]];
            }
            else{
                res += index;
                cmap[s[i]] = index;
                index += 1;
            }
        }
        return res;
    }
    */
    
    
};
