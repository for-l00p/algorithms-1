/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//http://yucoding.blogspot.com/2013/03/leetcode-question-80-remove-duplicates.html
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if( head == NULL || head->next == NULL) return head;
    ListNode* pre = new ListNode(0);
    pre -> next = head;
    head = pre;
    ListNode *p = head;
        
    while(p -> next != NULL){
      ListNode *suf = p -> next;
      while( suf -> next != NULL && suf -> val == suf -> next -> val){
	suf = suf -> next;
      }
      if( p -> next != suf){
	p -> next = suf -> next;
      }
      else{
	p = p -> next;
      }
    }
    return head -> next;
  }
};
