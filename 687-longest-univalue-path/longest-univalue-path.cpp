// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
//
// Note: The length of path between two nodes is represented by the number of edges between them.
//
//
// Example 1:
//
//
//
//
// Input:
//
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
//
//
//
//
// Output:
//
// 2
//
//
//
//
// Example 2:
//
//
//
//
// Input:
//
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
//
//
//
//
// Output:
//
// 2
//
//
//
// Note:
// The given binary tree has not more than 10000 nodes.  The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root){
        if(!root) return 0;
        int edges = 0;
        int this_node = rootPath(root, edges);
        int left_right = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(this_node, left_right);
    }
    
    int rootPath(TreeNode* root, int& num){
        if(root->left != NULL && root->right != NULL && root->val == root->left->val && root->val == root->right->val){
            num += 2;
            return max(rootPath(root->left, num), rootPath(root->right, num));
        }
        else{
            int left_max = num;
            num += 1;
            if(root->left != NULL && root->val == root->left->val)
                left_max = rootPath(root->left, num);

            int right_max = num;
            if(root->right != NULL && root->val == root->right->val)
                right_max = rootPath(root->right, num);
            return max(left_max, right_max);
        }
    }
    */
    
    int longestUnivaluePath(TreeNode* root){
        if(!root) return 0;
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, int& res){
        int l = root->left == NULL ? 0 : dfs(root->left, res);
        int r = root->right == NULL ? 0 : dfs(root->right, res);
        int resl = root->left && root->val == root->left->val ? l + 1 : 0;
        int resr = root->right && root->val == root->right->val ? r + 1 : 0;
        res = max(res, resl + resr);
        return max(resl, resr);
    }
};
