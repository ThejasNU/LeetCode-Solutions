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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        
        while(true){
            //Odd number of elements
            if(fast->next==nullptr) return slow;
            
            //Even number of elements
            else if(fast->next->next==nullptr) return slow->next;
            
            else{
                fast=fast->next->next;
                slow=slow->next;
            }
        }
        
    }
};