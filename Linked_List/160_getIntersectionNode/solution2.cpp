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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *nodeA = headA, *nodeB = headB;
    unordered_map<ListNode*, int> listNodeA;
    while(nodeA){
      listNodeA[nodeA] = 1;
      nodeA = nodeA->next;
    }
    while(nodeB){
      if(listNodeA.find(nodeB) != listNodeA.end()){
	return nodeB;
      }
      else{
	nodeB = nodeB->next;
      }
    }
    return NULL;
  }
};
