/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummySum = new ListNode(0);
    ListNode *p1 = l1, *p2 = l2, *cur = dummySum;
    int carry = 0, x, y;
    while(p1 || p2){
      if(p1) x = p1->val; else x = 0;
      if(p2) y = p2->val; else y = 0;
      int val = (x + y + carry) % 10;
      carry = (x + y + carry)/10;
      cur->next = new ListNode(val);
      cur = cur->next;
      if(p1) p1 = p1->next;
      if(p2) p2 = p2->next;
    }
    if(carry){
      cur->next = new ListNode(carry);
    }
    return dummySum->next;
  }
};
