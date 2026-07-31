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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=new ListNode(0);
       ListNode* b=temp;
       ListNode* tem=new ListNode(0);
       ListNode* a=tem;
       while(head!=NULL){
        if(head->val<x){
            temp->next=head;
            temp=temp->next;
            head=head->next;
        }
        else{
            tem->next=head;
            tem=tem->next;
            head=head->next;
        }
       }
       tem->next=NULL;
       temp->next=a->next;
       return b->next;
    }
};