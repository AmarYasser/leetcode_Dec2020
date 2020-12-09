/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int count=0;
    ListNode *current;
    Solution(ListNode* head) {
        current=head;
        
        while(current!=NULL){
            count+=1;
            current = current->next;
        }
        current=head;
    }
   
    /** Returns a random node's value. */
 
    int getRandom(){

    
      int ret = -1;
      int len = 1;
      ListNode* v = current;
      while(v){
         if(rand() % len == 0){
            ret = v->val;
         }
         len++;
         v = v->next;
      }
      return ret;
   }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */