//
// On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
//
// Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
//
//
// Example 1:
//
// Input: cost = [10, 15, 20]
// Output: 15
// Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
//
//
//
// Example 2:
//
// Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
// Output: 6
// Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
//
//
//
// Note:
//
// cost will have a length in the range [2, 1000].
// Every cost[i] will be an integer in the range [0, 999].
//
//


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost){
        int length = cost.size();
        
        if(length == 0)
            return 0;
        
        if(length == 1)
            return cost[0];
        
        int sum_last = cost[0];
        int sum_prior = cost[1];
        int sum_cur = 0;
        
        for(int i = 2; i < length; i++){
            sum_cur = cost[i] + min(sum_last, sum_prior);
            sum_last = sum_prior;
            sum_prior = sum_cur;
        }
        
        return min(sum_last, sum_prior);
    }
};
