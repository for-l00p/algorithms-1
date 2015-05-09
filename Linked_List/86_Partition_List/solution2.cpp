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
  ListNode *partition(ListNode *head, int x) {
    //exception handler
    if(head == NULL){
      return head;
    }
    
    //create branch dummy to normalize the process
    ListNode *leftDummy = new ListNode(0);
    ListNode *rightDummy = new ListNode(0);
    ListNode *leftNode = leftDummy;
    ListNode *rightNode = rightDummy;
    ListNode *node = head;
    
    //main function
    while(node!= NULL){
      if(node->val < x){
	leftNode->next = node;
	leftNode = leftNode->next;
      }
      else{
	rightNode->next = node;
	rightNode = rightNode->next;
      }
      //Don't forget to update the node in a loop.
      node = node->next;
    }
    
    //append right to left after reset and return
    leftNode->next = rightDummy->next;
    rightNode->next = NULL;
    return leftDummy->next;
  }
};
