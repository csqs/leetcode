// The string &quot;PAYPALISHIRING&quot; is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
//
// And then read line by line: &quot;PAHNAPLSIIGYIR&quot;
//
// Write the code that will take a string and make this conversion given a number of rows:
//
//
// string convert(string s, int numRows);
//
// Example 1:
//
//
// Input: s = &quot;PAYPALISHIRING&quot;, numRows = 3
// Output: &quot;PAHNAPLSIIGYIR&quot;
//
//
// Example 2:
//
//
// Input: s = &quot;PAYPALISHIRING&quot;, numRows =&nbsp;4
// Output:&nbsp;&quot;PINALSIGYAHRPI&quot;
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//


class Solution {
public:
    /*
    string convert(string s, int numRows){
        if(numRows <= 1) return s;
        
        vector<vector<char>> res(numRows, vector<char>(s.size() / (numRows + 1) * 2 + 1, '*'));
        int row = 0, col = 0;
        bool turn = false, up = false;
        for(int i = 0; i < s.size(); i++){
            res[row][col] = s[i];
            if((i + 1) % (numRows + 1) == numRows){
                row = numRows % 2 ? numRows / 2 : numRows / 2 - 1;
                col = col + 1;
                turn = true;
            }
            else{
                if(turn){
                    turn = false;
                    row = row == 0 ? numRows - 1 : 0;
                    up = row == 0 ? true : false;
                    col += 1;
                }
                else{
                    if(up) row--;
                    else row++;
                }
            }
        }

        string trans = "";
        for(auto m : res){
            for(auto n : m){
                string tmp  = "";
                if(n != '*') tmp.insert(0, 1, n);
                trans += tmp;
            }
        }
        
        return trans;
    }
    */
    string convert(string s, int numRows){
        if(numRows <= 1) return s;
        
        string *res = new string[numRows];
        int row = 0, step = 1;
        for(int i = 0; i < s.size(); i++){
            res[row].push_back(s[i]);
            
            if(row == 0)
                step = 1;
            else if(row == numRows - 1)
                step = -1;
            
            row += step;    
        }
        
        string trans = "";
        for(int i = 0; i < numRows; i++){
            trans += res[i];
        }
        
        return trans;
    }
    
};
