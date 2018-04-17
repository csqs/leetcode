// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//
// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.
//
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n) {
        /*
        vector<TreeNode*> res;
        
        if(n == 0)
            return res;
        
        if(n == 1){
            TreeNode* node = new TreeNode(1);
            res.push_back(node);
            return res;
        }
        
        vector<vector<TreeNode*>> history;
        vector<TreeNode*> record;
        TreeNode* node = new TreeNode(1);
        record.push_back(node);
        history.push_back(record);
        
        for(int i = 2; i <= n; i++){
            vector<TreeNode*> one_record;
            for(int root_index = i; root_index >= 1; root_index--){
                int left_number = root_index - 1;
                int right_number = i - root_index;
                
                if(left_number > 0 && right_number > 0){
                    vector<TreeNode*> left_childs = history[left_number - 1];
                    vector<TreeNode*> right_childs = history[right_number - 1];
                    
                    for(int j = 0; j < left_childs.size(); j ++)
                        for(int k = 0; k < right_childs.size(); k++){
                            TreeNode* root = new TreeNode(i);
                            root->left = nodeCopy(left_childs[j], 0);
                            root->right = nodeCopy(right_childs[k], i);
                            one_record.push_back(root);
                        }
                }
                else if(left_number > 0 && right_number == 0){
                    vector<TreeNode*> left_childs = history[left_number - 1];
                    
                    for(int j = 0; j < left_childs.size(); j ++){
                        TreeNode* root = new TreeNode(i);
                        root->left = nodeCopy(left_childs[j], 0);
                        one_record.push_back(root);
                    }
                }
                else if(left_number == 0 && right_number > 0){
                    vector<TreeNode*> right_childs = history[right_number - 1];
                    
                    for(int k = 0; k < right_childs.size(); k++){
                        TreeNode* root = new TreeNode(i);
                        root->right = nodeCopy(right_childs[k], i);
                        one_record.push_back(root);
                    }
                }
            }
        }
        
        return history.back();
        */
        
        vector<TreeNode*> res;
        if(n < 1)
            return res; 
        else
            return generateTree(1, n);
    }
    
    TreeNode* nodeCopy(TreeNode* head, int val){
        if(head == NULL)
            return NULL;
        
        TreeNode* newNode = new TreeNode(head->val + val);
        newNode->left = nodeCopy(head->left, val);
        newNode->right = nodeCopy(head->right, val);
        
        return newNode;
    }
    
    vector<TreeNode*> generateTree(int start, int end){
        vector<TreeNode*> res;
        
        if(start > end) res.push_back(NULL);
        else if(start == end) res.push_back(new TreeNode(start));
        else{
            for(int i = start; i <= end; i++){
                vector<TreeNode*> left_childs = generateTree(start, i - 1);
                vector<TreeNode*> right_childs = generateTree(i + 1, end);
                
                for(int j = 0; j < left_childs.size(); j++){
                    for(int k = 0; k < right_childs.size(); k++){
                        TreeNode* root = new TreeNode(i);
                        root->left = left_childs[j];
                        root->right = right_childs[k];
                        res.push_back(root);
                    }
                }
            }
        }
        
        return res;
    }
};
