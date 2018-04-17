// Given a string containing just the characters &#39;(&#39;, &#39;)&#39;, &#39;{&#39;, &#39;}&#39;, &#39;[&#39; and &#39;]&#39;, determine if the input string is valid.
//
// An input string is valid if:
//
//
// 	Open brackets must be closed by the same type of brackets.
// 	Open brackets must be closed in the correct order.
//
//
// Note that an empty string is&nbsp;also considered valid.
//
// Example 1:
//
//
// Input: &quot;()&quot;
// Output: true
//
//
// Example 2:
//
//
// Input: &quot;()[]{}&quot;
// Output: true
//
//
// Example 3:
//
//
// Input: &quot;(]&quot;
// Output: false
//
//
// Example 4:
//
//
// Input: &quot;([)]&quot;
// Output: false
//
//
// Example 5:
//
//
// Input: &quot;{[]}&quot;
// Output: true
//
//


class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for(auto ch : s){
            if(tmp.empty() || !isRight(tmp.top(), ch)) tmp.push(ch);
            else if(isRight(tmp.top(), ch)) tmp.pop();
        }
        return tmp.empty();
    }
    bool isRight(char left, char right){
        if(left == '(' && right == ')') return true;
        if(left == '{' && right == '}') return true;
        if(left == '[' && right == ']') return true;
        return false;
    }
};
