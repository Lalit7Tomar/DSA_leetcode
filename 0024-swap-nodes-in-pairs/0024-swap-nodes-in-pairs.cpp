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
    ListNode* swapPairs(ListNode* head) {
      ListNode* first=head;
      if(first==nullptr || first->next==nullptr){
        return first;
      }
      ListNode* second=first->next;
      ListNode* t=second;
      if(second->next==nullptr){
        second->next=first;
        first->next=nullptr;
        return second;
      }
      ListNode* third=second->next;
    ListNode* prev=nullptr;

      while(second!=nullptr){
        if(second!=nullptr) first->next=second->next;
        else if(second==nullptr){
            return t;
        }
      second->next=first;
      if(prev!=nullptr) prev->next=second;
      prev=first;
      first=third;
      if(first==nullptr){
        return t;
      }
      if(first!=nullptr) {
        second=first->next;
        if(second!=nullptr){
            third=second->next;
        }
      }}
     return t;


    }
};