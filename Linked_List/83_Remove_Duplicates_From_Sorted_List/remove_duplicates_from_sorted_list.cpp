/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

  For example,
  Given 1->1->2, return 1->2.
  Given 1->1->2->3->3, return 1->2->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// http://fisherlei.blogspot.com/2012/12/leetcode-remove-duplicates-from-sorted_5307.html
// Thanks to Techbow

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL){
            return head;
        }
        ListNode *curt = head;
        while(curt->next){
            if(curt->val == curt->next->val){
                ListNode *toDelete = curt->next;
                curt->next = curt->next->next;
                delete toDelete;
            }
            else{
                curt = curt->next;
            }
        }
        return head;
    }
};