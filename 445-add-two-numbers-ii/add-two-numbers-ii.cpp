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
        ListNode* list1=reverseLinkedList(l1);
        ListNode* list2=reverseLinkedList(l2);

        int sum=0;
        int carry;
        ListNode* ans=new ListNode(0);
        while(list1!=NULL || list2!=NULL){
            if(list1!=NULL){
                sum+=list1->val;
                list1=list1->next;
            }
            if(list2!=NULL){
                sum+=list2->val;
                list2=list2->next;
            }
            ans->val=sum%10;
            carry=sum/10;
            //to take care of edge case when there's carry left
            ListNode* temp=new ListNode(carry);
            temp->next=ans;
            ans=temp;
            sum=carry;
        }
        if(carry==0) return ans->next;
        else return ans;
    }

    ListNode* reverseLinkedList(ListNode* node){
        ListNode* prev=NULL;
        ListNode* nxt;
        while(node!=NULL){
            nxt=node->next;
            node->next=prev;
            prev=node;
            node=nxt;
        }
        return prev;
    }
};