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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* startNode=new ListNode();
        startNode->next=head;

        ListNode *p1=startNode,*p2=startNode,*p3=startNode;
        for(int i=0;i<k;++i){
            p1=p1->next;
            p3=p3->next;
        }
        while(p1!=NULL){
            p1=p1->next;
            p2=p2->next;
        }

        int temp=p2->val;
        p2->val=p3->val;
        p3->val=temp;
        return head;
    }
};