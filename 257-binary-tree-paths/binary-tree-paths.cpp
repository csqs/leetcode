//
// Given a binary tree, return all root-to-leaf paths.
//
//
// For example, given the following binary tree:
//
//
//
//    1
//  /   \
// 2     3
//  \
//   5
//
//
//
// All root-to-leaf paths are:
// ["1->2->5", "1->3"]
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)
            return res;

        string temp = "";
        preOrder(root, res, temp);
        return res;
    }
    
    void preOrder(TreeNode* root, vector<string> &res, string &temp){
        if(root->left == NULL && root->right == NULL){
            string new_res = temp + to_string(root->val);
            res.push_back(new_res);
        }
        string path = temp + to_string(root->val) + "->";
        if(root->left) preOrder(root->left, res, path);
        if(root->right) preOrder(root->right, res, path);
    }
    */
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        
        stack<string> temp_str;
        stack<TreeNode*> temp_node;
        
        temp_str.push("");
        temp_node.push(root);
        while(!temp_node.empty()){
            TreeNode* cur = temp_node.top();
            temp_node.pop();
            string str = temp_str.top();
            temp_str.pop();
            
            if(cur->left == NULL && cur->right == NULL){
                str += to_string(cur->val);
                res.push_back(str);
            }
            
            str += to_string(cur->val) + "->";
            if(cur->left != NULL){
                temp_str.push(str);
                temp_node.push(cur->left);
            }
            
            if(cur->right != NULL){
                temp_str.push(str);
                temp_node.push(cur->right);
            }
                
        }
        return res;
    }
};
