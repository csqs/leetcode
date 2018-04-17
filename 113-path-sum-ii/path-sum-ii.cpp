//
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
//
// For example:
// Given the below binary tree and sum = 22,
//
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
//
//
//
// return
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
//
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        
        stack<TreeNode*> nodes;
        stack<vector<int>> paths;
        
        nodes.push(root);
        vector<int> first_path;
        first_path.push_back(root->val);
        paths.push(first_path);
        while(!nodes.empty()){
            TreeNode* cur = nodes.top();
            nodes.pop();
            vector<int> path = paths.top();
            paths.pop();
            
            int total = 0;
            for(auto n : path)
                total += n;
            
            if(total == sum && cur->left == NULL && cur->right == NULL){
                res.push_back(path);
            }
            else{
                if(cur->left != NULL){
                    nodes.push(cur->left);
                    vector<int> left_path = path;
                    left_path.push_back(cur->left->val);
                    paths.push(left_path);
                }
                if(cur->right != NULL){
                    nodes.push(cur->right);
                    vector<int> right_path = path;
                    right_path.push_back(cur->right->val);
                    paths.push(right_path);
                }
            }
        }
        return res;
    }
};
