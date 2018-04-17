// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example:
//
//
// Input: &quot;23&quot;
// Output: [&quot;ad&quot;, &quot;ae&quot;, &quot;af&quot;, &quot;bd&quot;, &quot;be&quot;, &quot;bf&quot;, &quot;cd&quot;, &quot;ce&quot;, &quot;cf&quot;].
//
//
// Note:
//
// Although the above answer is in lexicographical order, your answer could be in any order you want.
//


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        
        stack<vector<string> > history;
        history.push(res);
        for(int i = 0; i < digits.size(); i++){
            strgAddDigit(history, digits[i]);
        }
        
        res = history.top();
        return res;    
    }
    
    void strgAddDigit(stack<vector<string> > &res, char num){
        vector<char> substr = returnChar(num);
        vector<string> cur = res.top();
        res.pop();
        vector<string> next;
        
        if(cur.empty()){
            for(auto str2 : substr){
                string temp = "0";
                temp[0] = str2;
                next.push_back(temp);
            }
        }
        else{
            for(auto str1 : cur){
                for(auto str2 : substr){
                    next.push_back(str1 + str2);
                }
            }
        }
        
        res.push(next);
    }
    
    vector<char> returnChar(char num){
        vector<char> res;
        if(num < '2' || num > '9') return res;
        else if(num == '9'){
            for(int i = 0; i < 4; i++){
                res.push_back('w' + i);
            }
        }
        else if(num == '7'){
            for(int i = 0; i < 4; i++){
                res.push_back('p' + i);
            }
        }
        else if(num == '8'){
            for(int i = 0; i < 3; i++){
                res.push_back('t' + i);
            }
        }
        else{
            for(int i = 0; i < 3; i++){
                res.push_back('a' + (num - '2') * 3 + i);    
            }
        }
        return res;
    }
    
};
