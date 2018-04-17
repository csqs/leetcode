// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//
// Example
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        
        int extra = 0;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        
        ListNode* ptr = new ListNode(0);
        ListNode* res = ptr;
        while(ptr1 || ptr2){
            int num1 = ptr1 ? ptr1->val : 0;
            int num2 = ptr2 ? ptr2->val : 0;
            ptr->val = num1 + num2 + extra;
            
            if(ptr->val >= 10){
                extra = 1;
                ptr->val %= 10;
            }
            else extra = 0;
            
            ptr1 = ptr1 ? ptr1->next : ptr1;
            ptr2 = ptr2 ? ptr2->next : ptr2;
            if(ptr1 || ptr2){
                ListNode* nextNode = new ListNode(0);
                ptr->next = nextNode;
                ptr = ptr->next;
            }
        }
        if(extra){
            ListNode* lastNode = new ListNode(1);
            ptr->next = lastNode;
        }
        
        return res;
    }
};
