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
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        
        if(head==nullptr || head->next==nullptr) return false;
        
        while(fast!=nullptr && fast->next !=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) return true;
        }
        
        return false;
    }
};