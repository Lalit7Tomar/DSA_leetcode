class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      // x,x=x%n,n-x-x%n
      // nodes intersect at n-x-x%n ahead of intersection,n-x%n=slowlength,n=fastlength
       // index=fast length-slowlength
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