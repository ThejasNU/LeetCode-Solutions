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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode nodeBefHead= ListNode();
        ListNode* p=& nodeBefHead;
        
       
        
        while(list1 && list2){
            if(list1->val < list2->val){
                p->next= new ListNode(list1->val);
                list1=list1->next;
                p=p->next;
            }
            else{
                p->next= new ListNode(list2->val);
                list2=list2->next;
                p=p->next;
            }
        }
        
        if(list1){
            while(list1){
                p->next= new ListNode(list1->val);
                p=p->next;
                list1=list1->next;
            }
        }
        else if(list2){
                while(list2){
                    p->next= new ListNode(list2->val);
                    p=p->next;
                    list2=list2->next;
                }
        }
        
        return nodeBefHead.next;
        
    }
};