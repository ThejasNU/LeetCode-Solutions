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
    
    ListNode* swapNodes(ListNode* head){
        ListNode* prevptr=nullptr;
        ListNode* currptr=head;
        ListNode* nextptr;
        
        int count=0;
        
        while(currptr!=nullptr && count<2){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            count++;
        }
        
        if(nextptr != nullptr){
            head->next=swapNodes(nextptr);
        }
        
        return prevptr;
    }
    
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next ==nullptr) return head;
        
        ListNode* newHead=swapNodes(head);
        
        return newHead;
        
        
    }
};