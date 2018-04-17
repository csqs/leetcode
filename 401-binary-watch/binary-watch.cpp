// A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
// Each LED represents a zero or one, with the least significant bit on the right.
//
// For example, the above binary watch reads "3:25".
//
// Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
//
// Example:
// Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//
//
// Note:
//
// The order of output does not matter.
// The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
// The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
//
//


class Solution {
public:
    /*
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        if(num < 0) return res;
        for(int i = 0; i <= num; i++){
            showHourMin(res, i, num - i);
        }
        return res;
    }
    
    void showHourMin(vector<string> &res, int hour, int min){
        vector<string> hours;
        returnHours(hours, hour);
        
        vector<string> mins;
        returnMins(mins, min);
        
        for(auto str1 : hours){
            for(auto str2 : mins){
                res.push_back(str1 + ":" + str2);
            }
        }
    }
    
    void returnHours(vector<string> &res, int hour){
        if(hour == 0){
            res.push_back("0");
            return;
        }
        
        vector<int> nums;
        int init = 1;
        for(int i = 0; i < 4; i++){
            nums.push_back(init);
            init <<= 1;
        }
        
        set<int> strs;
        while(next_permutation(nums.begin(), nums.end())){
            int temp = 0;
            for(int i = 0; i < hour; i++){
                temp += nums[i];
            }
            if(temp < 12 && strs.find(temp) == strs.end())
                strs.insert(temp);
        }
        
        for(auto n : strs){
            res.push_back(to_string(n));
        }
    }
    
    void returnMins(vector<string> &res, int min){
        if(min == 0){
            res.push_back("00");
            return;
        }
        
        vector<int> nums;
        int init = 1;
        for(int i = 0; i < 6; i++){
            nums.push_back(init);
            init <<= 1;
        }
        
        set<int> strs;
        while(next_permutation(nums.begin(), nums.end())){
            int temp = 0;
            for(int i = 0; i < min; i++){
                temp += nums[i];
            }
            if(temp < 60 && strs.find(temp) == strs.end())
                strs.insert(temp);
        }
        
        for(auto n : strs){
            if(n < 10) res.push_back("0" + to_string(n));
            else res.push_back(to_string(n));
        }
    }
    */
    
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        helper(res, make_pair(0, 0), num, 0);
        return res;
    }
    
    void helper(vector<string> &res, pair<int, int> time, int num, int begin){
        if(num == 0){
            res.push_back(to_string(time.first) + (time.second < 10 ? ":0" : ":") + to_string(time.second));
            return;
        }
        
        for(int i = begin; i < hour.size() + min.size(); i++){
            if(i < hour.size()){
                time.first += hour[i];
                if(time.first < 12) helper(res, time, num - 1, i + 1);
                time.first -= hour[i];
            }
            else{
                time.second += min[i - hour.size()];
                if(time.second < 60) helper(res, time, num - 1, i + 1);
                time.second -= min[i - hour.size()];
            }
        }
    }
    
private:
    vector<int> hour = {1, 2, 4, 8}, min = {1, 2, 4, 8, 16, 32};
};
