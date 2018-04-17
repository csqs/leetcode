// Given a binary tree, return the postorder traversal of its nodes&#39; values.
//
// For example:
// Given binary tree [1,null,2,3],
//
//
//    1
//     \
//      2
//     /
//    3
//
//
// &nbsp;
//
// return [3,2,1].
//
// Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        postOrder(root, res);
        return res;
    }
    
    void postOrder(TreeNode* root, vector<int> &res){
        if(root->left != NULL) postOrder(root->left, res);
        if(root->right != NULL) postOrder(root->right, res);
        res.push_back(root->val);
    }
    */
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> toVisit;
        TreeNode* curNode = root;
        TreeNode* preNode = NULL;
            
        while(curNode || !toVisit.empty()){
            if(curNode){
                toVisit.push(curNode);
                curNode = curNode->left;
            }
            else{
                TreeNode* topNode = toVisit.top();
                if(topNode->right && preNode != topNode->right){
                    curNode = topNode->right;
                }
                else{
                    res.push_back(topNode->val);
                    preNode = topNode;
                    toVisit.pop();
                }
            }
        }
              
        return res;
        
    }
    
    
};
