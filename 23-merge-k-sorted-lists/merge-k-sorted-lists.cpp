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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* head = new ListNode();
        ListNode* temp = head;
        while(left && right){
            if(left->val > right-> val){
                temp->next = right;
                temp = temp->next;
                right = right->next;
                temp->next = nullptr;
                
            }else{
                temp->next = left;
                temp = temp->next;
                left = left->next;
                temp->next = nullptr;
                
            }

        }
        
        if(left){
            temp->next = left;
        }else if(right){
            temp->next = right;
        }
        
        return head->next;
    }



    ListNode* mergeSort(vector<ListNode*>& lists, int l, int r){
        if(l==r)return lists[l];
        int mid = (l + r) / 2;
        ListNode* left = mergeSort(lists, l, mid);
        ListNode* right = mergeSort(lists, mid+1, r);
        return merge(left, right);
    }



public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // we will use merge and sort method
        if (lists.empty()) {
            return nullptr;
        }
        return mergeSort(lists, 0, lists.size()-1);
    }
};