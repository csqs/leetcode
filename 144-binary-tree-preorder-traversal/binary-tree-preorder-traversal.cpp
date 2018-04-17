// Given a binary tree, return the preorder traversal of its nodes' values.
//
//
// For example:
// Given binary tree [1,null,2,3],
//
//    1
//     \
//      2
//     /
//    3
//
//
//
// return [1,2,3].
//
//
// Note: Recursive solution is trivial, could you do it iteratively?


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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        preOrder(root, res);
        return res;
    }
    
    void preOrder(TreeNode* root, vector<int> &res){
        res.push_back(root->val);
        if(root->left != NULL) preOrder(root->left, res);
        if(root->right != NULL) preOrder(root->right, res);
    }
};
