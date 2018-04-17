// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
// Note: You may not slant the container and n is at least 2.
//


class Solution {
public:
    /*
    int maxArea(vector<int>& height) {
        int res = 0, len = height.size();
        for(int i = 0; i < len; i++){
            for(int j = len - 1; j > i; j--){
                if(res > (j - i) * height[i])
                    break;
                
                int tmp = (j - i) * min(height[i], height[j]);
                if(res < tmp) res = tmp;
            }
        }
        return res;
    }
    */
    
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while(j > i){
            int h = min(height[i], height[j]);
            res = res < h * (j - i) ? h * (j - i) : res;
            while(j > i && height[j] <= h) j--;
            while(j > i && height[i] <= h) i++;
        }
        return res;
    }
};
