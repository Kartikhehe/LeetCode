/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)return nullptr;

        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while(fast!=nullptr && fast->next!=nullptr && fast!=slow ){
            if(!fast)return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }

        slow = head;
        while(fast!=nullptr && fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }return fast;
    }
};