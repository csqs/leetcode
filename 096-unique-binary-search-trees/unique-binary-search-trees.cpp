// Given n, how many structurally unique BST&#39;s (binary search trees) that store values 1...n?
//
// For example,
// Given n = 3, there are a total of 5 unique BST&#39;s.
//
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//
//
// &nbsp;
//


class Solution {
public:
    int numTrees(int n) {
        if(n < 1)
            return 0;
        if(n == 1)
            return 1;
        
        vector<int> history;
        history.push_back(1);
        
        for(int i = 1; i < n; i++){
            int res = 0;
            for(int node_index = i + 1; node_index >= 1; node_index--){
                int left_num = node_index - 1;
                int right_num = (i + 1) - node_index;
                
                if(left_num > 0){
                    left_num = history[left_num - 1];
                }
                else{
                    left_num = 1;
                }
                if(right_num > 0){
                    right_num = history[right_num - 1];
                }
                else{
                    right_num = 1;
                }
                
                res += left_num * right_num;
            }
            history.push_back(res);
        }
        
        return history.back();
    }
};
