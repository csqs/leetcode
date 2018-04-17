// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
//
// Example 1
// Input: "2-1-1". 
// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Output: [0, 2]
//
// Example 2
// Input: "2*3-4*5" 
// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
// Output: [-34, -14, -10, -10, 10] 
//
// Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap;
        return computeResult(input, dpMap);
    }
    
    vector<int> computeResult(string input, unordered_map<string, vector<int>> &dpMap){
        vector<int> res;
        for(int i = 0; i < input.size(); i++){
            char curInput = input[i];
            if(curInput == '+' || curInput == '-' || curInput == '*'){
                vector<int> result1, result2;
                string substr1 = input.substr(0, i);
                if(dpMap.find(substr1) != dpMap.end())
                    result1 = dpMap[substr1];
                else
                    result1 = computeResult(substr1, dpMap);
                
                string substr2 = input.substr(i + 1);
                if(dpMap.find(substr2) != dpMap.end())
                    result2 = dpMap[substr2];
                else
                    result2 = computeResult(substr2, dpMap);
                
                for(auto m : result1)
                    for(auto n : result2){
                        if(curInput == '+')
                            res.push_back(m + n);
                        else if(curInput == '-')
                            res.push_back(m - n);
                        else
                            res.push_back(m * n);
                    }
            }       
        }
        if(res.empty())
            res.push_back(atoi(input.c_str()));
                   
        dpMap[input] = res;
        return res;
    }
        
};
