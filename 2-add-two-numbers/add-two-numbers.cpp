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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        int pass = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + pass;
            temp->next = new ListNode();
            temp = temp->next;
            temp->val = sum%10;
            pass = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            int sum = l1->val + pass;
            temp->next = new ListNode();
            temp = temp->next;
            pass = sum/10;
            temp->val = sum%10;
            l1 = l1->next;
        }

        while(l2){
            int sum = l2->val + pass;
            temp->next = new ListNode();
            temp = temp->next;
            pass = sum/10;
            temp->val = sum%10;
            l2 = l2->next;
        }

        while(pass){
            temp->next = new ListNode();
            temp = temp->next;
            temp->val = pass%10;
            pass/= 10;
        }
        return head->next;
    }
};