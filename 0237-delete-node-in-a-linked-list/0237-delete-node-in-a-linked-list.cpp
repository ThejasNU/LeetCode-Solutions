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
    void deleteNode(ListNode* node) {
        if(node==NULL) return;
        
        ListNode* pres=node;
        ListNode* prev;
        
        while(pres->next!=NULL){
            swap(pres->val,pres->next->val);
            prev=pres;
            pres=pres->next;
        }
        prev->next=NULL;
    }
};