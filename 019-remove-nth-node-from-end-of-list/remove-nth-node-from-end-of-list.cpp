// Given a linked list, remove the n-th node from the end of list and return its head.
//
// Example:
//
//
// Given linked list: 1-&gt;2-&gt;3-&gt;4-&gt;5, and n = 2.
//
// After removing the second node from the end, the linked list becomes 1-&gt;2-&gt;3-&gt;5.
//
//
// Note:
//
// Given n will always be valid.
//
// Follow up:
//
// Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n <= 0) return head;
        
        ListNode* ptr = head;
        while(n){
            if(ptr == NULL) return head->next;
            ptr = ptr->next;
            n--;
        }
        
        ListNode* first = new ListNode(-1);
        first->next = head;
        ListNode* pre = first;
        ListNode* cur = head;
        while(ptr){
            ptr = ptr->next;
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = cur->next;
        
        return first->next;
    }
};
