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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;

        while(curr != NULL){
           ListNode* child = curr->next;
           curr->next = prev;
           prev = curr;
           curr = child;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(second != NULL){
            ListNode* firstchild = first->next;
            ListNode* secondchild = second->next;

            first->next = second;
            second->next = firstchild;

            first = firstchild;
            second = secondchild;
        }

        return;
    }
};
