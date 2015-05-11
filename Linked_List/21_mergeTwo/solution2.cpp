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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *merged = new ListNode(0);
    ListNode *node = merged;
    while(l1 || l2){
      if(l1 && l2){
	if(l1->val < l2->val){
	  node->next = new ListNode(l1->val);
	  l1 = l1->next;
	}
	else{
	  node->next = new ListNode(l2->val);
	  l2 = l2->next;
	}
      }
      else if(l1){
	node->next = new ListNode(l1->val);
	l1 = l1->next;
      }
      else{
	node->next = new ListNode(l2->val);
	l2 = l2->next;
      }
      node = node->next;
    }
    return merged->next;
  }
};
