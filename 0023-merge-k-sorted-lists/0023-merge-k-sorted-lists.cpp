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
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode dummy(0);      
        ListNode* tail = &dummy;
       while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next; 
        }

        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }

        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0 || lists.size()==1){
            if(lists.size()==0){
                return nullptr;
            }
            return lists.front();
        }
       //binarysearch lgega
       while(lists.size()>1){
        ListNode* a=lists[lists.size()-1];
        lists.pop_back();
        ListNode* b=lists[lists.size()-1];
        lists.pop_back();
        ListNode* c=merge(a,b);
        lists.push_back(c);
       }
       ListNode* c=lists.front();
       return c;
    }
    
};