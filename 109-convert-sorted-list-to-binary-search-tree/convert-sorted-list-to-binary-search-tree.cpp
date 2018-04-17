// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//
//
//
// Example:
//
// Given the sorted linked list: [-10,-3,0,5,9],
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return midNode(head, NULL);
    }
    
    TreeNode* midNode(ListNode* head, ListNode* tail){
        if(head == tail)
            return NULL;
        
        if(head->next == tail){
            TreeNode* node = new TreeNode(head->val);
            return node;
        }
            
        ListNode* mid = head, *nextNode = head;
        while(nextNode != tail && nextNode->next != tail){
            mid = mid->next;
            nextNode = nextNode->next->next;
        }
        
        TreeNode* root = new TreeNode(mid->val);
        root->left = midNode(head, mid);
        root->right = midNode(mid->next, tail);
        
        return root;
    }
};
