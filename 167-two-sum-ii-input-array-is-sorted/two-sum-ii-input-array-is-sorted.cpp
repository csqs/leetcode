// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
// You may assume that each input would have exactly one solution and you may not use the same element twice.
//
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2
//


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int start_index = 0;
        int end_index = numbers.size() - 1;
        while(end_index > start_index){
            int res_temp = numbers[end_index] + numbers[start_index];
            if(res_temp > target)
                end_index --;
            else if(res_temp < target)
                start_index ++;
            else{
                res.push_back(start_index + 1);
                res.push_back(end_index + 1);
                break;
            }
        }
        return res;
    }
};
