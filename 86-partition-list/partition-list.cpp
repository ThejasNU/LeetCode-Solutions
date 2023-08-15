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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* last=new ListNode(0,head);
        ListNode* newRoot=last;
        ListNode* prev=last;
        ListNode* cur=head;

        while(cur!=NULL){
            if(cur->val<x){
                ListNode* lastNext=last->next;
                if(lastNext==cur){
                    last=lastNext;
                    prev=cur;
                    cur=cur->next;
                    continue;
                }
                ListNode* curNext=cur->next;
                last->next=cur;
                cur->next=lastNext;
                prev->next=curNext;
                cur=curNext;
                last=last->next;
            }
            else{
                prev=cur;
                cur=cur->next;
            }
        }
        return newRoot->next;
    }
};