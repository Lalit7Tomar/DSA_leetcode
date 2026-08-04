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