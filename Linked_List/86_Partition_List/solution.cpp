/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
  void insert_end(ListNode *head, int x){
    while(head -> next != NULL){
      head = head -> next;
    }
    ListNode *end = new ListNode(x);
    head -> next = end;
  }
    
  void append(ListNode *p, ListNode *tail){
    if( p == NULL){
      p -> next = tail;
    }
    while(p -> next != NULL){
      p = p->next;
    }
    p->next = tail;
  }
    
  ListNode *partition(ListNode *head, int x) {
    ListNode *lt_h = new ListNode(0);
    ListNode *gte_h = new ListNode(0);
    ListNode *p = head;
    while (p != NULL){
      if( p -> val < x ){
	insert_end(lt_h, p->val);
      }
      else {
	insert_end(gte_h, p->val);
      }
      p = p -> next;
    }
    append(lt_h, gte_h ->next);
    delete gte_h;
    return lt_h -> next;
  }
};
