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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = head;
        ListNode* right = dummy;
    
        while(n > 0){
            left = left->next;
            n--;
        }

        while(left != NULL){
            left = left->next;
            right = right->next;
        }

        right->next = right->next->next;

        return dummy->next;
    }
};
