class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode* slow=head;
       ListNode* fast=head;
       bool result=false;
       while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
         if(fast!=nullptr && slow==fast){
            return true;
         }
       }
       return false;
    }
};