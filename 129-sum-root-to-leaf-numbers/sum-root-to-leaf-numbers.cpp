// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
// An example is the root-to-leaf path 1-&gt;2-&gt;3 which represents the number 123.
//
// Find the total sum of all root-to-leaf numbers.
//
// For example,
//
//
//     1
//    / \
//   2   3
//
//
// &nbsp;
//
// The root-to-leaf path 1-&gt;2 represents the number 12.
// The root-to-leaf path 1-&gt;3 represents the number 13.
//
// Return the sum = 12 + 13 = 25.
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        
        vector<int> res;
        stack<TreeNode*> nodes;
        stack<vector<int>> paths;
        
        nodes.push(root);
        vector<int> init;
        init.push_back(root->val);
        paths.push(init);
        
        while(!nodes.empty()){
            TreeNode* cur = nodes.top();
            nodes.pop();
            vector<int> path = paths.top();
            paths.pop();
            
            if(cur->left == NULL && cur->right == NULL){
                int one_res = 0;
                for(int i = 0; i < path.size(); i++){
                    one_res = path[i] + one_res * 10;
                }
                res.push_back(one_res);
            }
            else{
                if(cur->left != NULL){
                    vector<int> left_path = path;
                    left_path.push_back(cur->left->val);
                    paths.push(left_path);
                    nodes.push(cur->left);
                }
                if(cur->right != NULL){
                    vector<int> right_path = path;
                    right_path.push_back(cur->right->val);
                    paths.push(right_path);
                    nodes.push(cur->right);
                }
            }
        }
        
        int res_num = 0;
        for(auto n : res)
            res_num += n;
        
        return res_num;
    }
    */
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        sum = 0;
        dfs(root, 0);
        return sum;
    }
    void dfs(TreeNode* root, int cur){
        if(!root) return;
        cur = root->val + cur * 10;
        if(root->left == NULL && root->right == NULL){
            sum += cur;
        }
        
        if(root->left != NULL){
            dfs(root->left, cur);
        }
        
        if(root->right != NULL){
            dfs(root->right, cur);
        }
            
    }
    
private:
    int sum;
};
