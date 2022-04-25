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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *ptr;
        
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        
        if(list1->val <= list2->val) {
            ptr = list1;
            list1 = list1->next;
        } else {
            ptr = list2;
            list2 = list2->next;
        }
        
        ListNode *tail = ptr;
        
        while(list1 != NULL && list2 != NULL) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                // tail = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                // tail = list2;
                list2 = list2->next;
            }
            
            tail = tail->next;
        }
        
        // adding remaining elements of bigger list.
        if(!list1)
            tail -> next = list2;
        else
            tail -> next = list1;
        
        return ptr;
    }
};