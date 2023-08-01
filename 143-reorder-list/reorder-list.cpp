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
        if(head->next==NULL) return;

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* secondHalfHead=slow->next;
        slow->next=NULL;

        ListNode* l1=head;
        ListNode* l2=secondHalfHead;

        function<ListNode*(ListNode*)> reverse=[](ListNode* node)->ListNode*{
            ListNode* prev=NULL;
            ListNode* cur=node;
            ListNode* nxt;

            while(cur!=NULL){
                nxt=cur->next;
                cur->next=prev;
                prev=cur;
                cur=nxt;
            }

            return prev;
        };

        function<void(ListNode*,ListNode*)> merge=[](ListNode* first,ListNode* last)->void{
            ListNode* nxtL;
            ListNode* nxtF;
            while(first!=NULL){
                nxtF=first->next;
                if(last!=NULL) nxtL=last->next;

                first->next=last;
                if(nxtF==NULL) break;
                last->next=nxtF;

                first=nxtF;
                last=nxtL;
            }
        };

        ListNode* revLastNodesHead=reverse(secondHalfHead);
        merge(head,revLastNodesHead);
        return;
    }
};