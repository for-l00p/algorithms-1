/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//http://yucoding.blogspot.com/2013/05/leetcode-question-108-swap-nodes-in.html
//http://blog.csdn.net/kenden23/article/details/17004749
// Thanks to TechBow, just change the value. No bother to change the pointer
// Using iteration, swapFirstTwo()
class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *node = dummy;
    while(node->next && node->next->next){
      int valHolder = node->next->val;
      node->next->val = node->next->next->val;
      node->next->next->val = valHolder;
      node = node->next->next;
    }
    return dummy -> next;
  }
};
