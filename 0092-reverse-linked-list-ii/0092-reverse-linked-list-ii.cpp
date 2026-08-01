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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
     if (head == nullptr || head->next == nullptr || left == right) {
            return head;
        }

        ListNode* before = head;
        if (left == 1) {
            before = nullptr;
        } else {
            for (int i = 1; i < left - 1; i++) {
                before = before->next;
            }
        }

        ListNode* after = head;
        for (int i = 1; i < right; i++) {
            after = after->next;
        }

        ListNode* temp;
        if (before != nullptr) {
            temp = before->next;
        } else {
            temp = head;
        }

        ListNode* dest = after->next;

        while (temp != after) {
            ListNode* ahead = temp->next;
            temp->next = dest;
            dest = temp;
            temp = ahead;                
        }

        temp->next = dest;

        if (before != nullptr) {
            before->next = temp;
            return head;
        }

        return temp;
    }
};