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
    int length(ListNode *node){
        ListNode *temp=node;
        int count=0;
        
        while(temp){
            temp=temp->next;
            count++;
        }
        
        return count;
    }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=length(headA);
        int lenB=length(headB);
        
        if(lenA>lenB){
            for(int i=0;i<lenA-lenB;++i){
                headA=headA->next;
            }
        }
        else if(lenA<lenB){
            for(int i=0;i<lenB-lenA;++i){
                headB=headB->next;
            }
        }
        
        while(headA  && headB){
            if(headA == headB){
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};