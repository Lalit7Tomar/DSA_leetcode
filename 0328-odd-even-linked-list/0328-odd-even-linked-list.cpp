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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* odd=head;
        ListNode* even=odd->next;
        ListNode* a=odd;
        ListNode* b=even;
        while(even!=nullptr && odd!=nullptr){
            odd->next=even->next;
            if(odd->next!=nullptr)  odd=odd->next;

            even->next=odd->next;
            even=even->next;
        }
        odd->next=b;
        return head;
    }
};