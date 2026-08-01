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
    ListNode *detectCycle(ListNode *head) {
       ListNode* a=head;
      ListNode* b=head;
       // check loop exist
       bool result=false;
       while(b!=nullptr && b->next!=nullptr){
        a=a->next;
        b=b->next->next;
         if(a==b){
            result=true;
            break;
         }
       }
       if(result==false){
         return nullptr;
       }
       b=head;
       while(a!=b){
        a=a->next;
        b=b->next;
       }
       return a;
    }
};