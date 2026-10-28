class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        vector<int> vals;
        while (head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }
        
        int left = 0, right = vals.size() - 1;
        while (left < right) {
            if (vals[left] != vals[right]) return false;
            left++;
            right--;
        }
        
        return true;
    }
};