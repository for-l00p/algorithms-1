/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

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
  ListNode *rotateRight(ListNode *head, int k) {
    if(head == NULL){
      return head;
    }
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;
        
    int len = 0;
    while(head!=NULL){
      len++;
      head = head->next;
    }

    for(int i = 0; i < k % len; i++){
      fast = fast->next;
    }
        
    while(fast->next!=NULL){
      fast = fast->next;
      slow = slow->next;
    }
        
    fast->next = dummy->next;
    dummy->next = slow->next;
    slow->next = NULL;
        
    return dummy->next;
  }
};
