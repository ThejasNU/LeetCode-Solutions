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
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            //if cycle is detected
            if(fast==slow){
                //edge case: when cycle begins at head
                if(fast==head && slow==head) return head;
                fast=head;
                while(fast->next != slow->next){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow->next;
            }
        }
        return NULL;
    }
};