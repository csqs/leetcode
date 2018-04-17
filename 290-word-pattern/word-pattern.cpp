// Given a pattern and a string str, find if str follows the same pattern.
//  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
// Examples:
//
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
//
//
//
//
// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
//
//
// Credits:Special thanks to @minglotus6 for adding this problem and creating all test cases.


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs;
        istringstream in(str);
        string word;
        while(in >> word){
            strs.push_back(word);
        }
        
        if(pattern.size() == strs.size()){
            unordered_map<char, string> pmap;
            unordered_map<string, char> smap;
            for(int i = 0; i < pattern.size(); i++){
                char key = pattern[i];
                string word = strs[i];
                if(pmap.find(key) != pmap.end() || smap.find(word) != smap.end()){
                    if(pmap[key] != word || smap[word] != key)
                        return false;
                }
                else{
                    pmap[key] = word;
                    smap[word] = key;
                }
            }
            return true;
        }
        
        return false;    
    }
};
