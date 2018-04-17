// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//
//
//
// Example:
//
// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        return midNode(nums, 0, nums.size());
    }
    
    TreeNode* midNode(vector<int>& nums, int begin, int end){
        if(begin == end)
            return NULL;
        else if(begin + 1 == end){
            TreeNode* node = new TreeNode(nums[begin]);
            return node;
        }
        
        int mid = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = midNode(nums, begin, mid);
        root->right = midNode(nums, mid + 1, end);
        
        return root;
    }
};
