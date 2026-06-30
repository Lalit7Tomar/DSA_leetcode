class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* curr=head;
    ListNode *prev=nullptr;
    if(curr==nullptr){
        return head;
    }
    ListNode *nex=head->next;
    while(curr!=nullptr){
        curr->next=prev;
        prev=curr;
        curr=nex;
        if(curr==nullptr){
            break;
        }
        nex=curr->next;
        
    }
    return prev;

 }
};
    