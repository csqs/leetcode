// Given a binary tree, return the inorder traversal of its nodes' values.
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
// return [1,3,2].
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        
        inorder(root, res);
        return res;
    }
    
    void inorder(TreeNode* root, vector<int> &res){
        if(root->left != NULL)
           inorder(root->left, res);
        if(root != NULL)
            res.push_back(root->val);
        if(root->right != NULL)
            inorder(root->right, res);
    }
};
