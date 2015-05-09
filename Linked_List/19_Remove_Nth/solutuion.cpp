/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0);
    dummy -> next = head;
    ListNode *pioneer = dummy;
    ListNode *delNext = dummy;
    for (int i = 0; i < n; i++){
      pioneer = pioneer -> next;
      if(pioneer == NULL){
	return NULL;
	break;
      }
    }
    while(pioneer -> next != NULL){
      pioneer = pioneer->next;
      delNext =  delNext->next;
    }
    ListNode *toDelete = delNext->next;
    delNext -> next = delNext -> next -> next;
    delete toDelete;
    return dummy -> next;
  }
};
