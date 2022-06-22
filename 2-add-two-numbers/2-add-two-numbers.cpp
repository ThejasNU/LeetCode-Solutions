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
        
        ListNode nodeBefHead= ListNode();
        
        ListNode *p = &nodeBefHead;
        
        int carry=0;
        int extra;
        
        while(l1 || l2 || carry){
            extra=0;
            
            extra+=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            
            p->next= new ListNode(extra % 10);
            
            carry=extra/10;
            
            l1=(l1?l1->next:l1);
            l2=(l2?l2->next:l2);
            p=p->next;
        }
        
        return nodeBefHead.next;
    }
};