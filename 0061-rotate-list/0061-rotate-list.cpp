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
    ListNode* rotateRight(ListNode* head, int k) {
         ListNode* temp=head;
       if(head==NULL || head->next==NULL|| k==0){
        return head;
       }
       //find length
       int i=1;
       while(temp->next!=NULL){
        i++;
        temp=temp->next;
       }
       k=k%i;
       if(k==0){
        return head;
       }
       i=i-k-1;
       ListNode* tem=head;
       for(int j=0;j<i;j++){
        tem=tem->next;
       }
       ListNode* t=tem->next;
       temp->next=head;
       tem->next=NULL;
       return t;
    }
};