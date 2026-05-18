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
    ListNode* merge(ListNode* curr, ListNode* next){
        ListNode* res = new ListNode(0);
        ListNode* prev = res;
        while(curr != NULL && next != NULL){
           if(curr->val < next->val){
            prev->next = curr;
            curr = curr->next;
           }else{
            prev->next = next;
            next = next->next;
           }
           prev = prev->next;
        }

        if(curr != NULL){
            prev->next = curr;
        }
        if(next != NULL){
            prev->next = next;
        }
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        while(lists.size() > 1){
            vector<ListNode*> merged;
            for(int i = 0; i< lists.size(); i+= 2){
                ListNode* curr = lists[i];
                ListNode* next = NULL;
                if(i+1 < lists.size()){
                    next = lists[i+1];
                }
                merged.push_back(merge(curr, next));
            }
            lists = merged;
        }

        return lists[0];
    }
};
