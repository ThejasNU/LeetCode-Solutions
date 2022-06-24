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
    ListNode* swapNodes(ListNode* head,int k){
        ListNode* prevptr=nullptr;
        ListNode* currptr=head;
        ListNode* nextptr;
        ListNode* temp=head;
        
        for(int i = 0; i < k; i++){
            if(temp == nullptr) return head;
            temp = temp->next;
        }
        
        int count=0;
        
        while(currptr!=nullptr && count<k){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            count++;
        }
        
        if(nextptr != nullptr){
            head->next=swapNodes(nextptr,k);
        }
        
        return prevptr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next ==nullptr || k==1) return head;
        
        ListNode* newHead=swapNodes(head,k);
        
        return newHead;
    }
};