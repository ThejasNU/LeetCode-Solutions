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
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        if(list1->val>list2->val) swap(list1,list2);

        ListNode* root=list1;
        while(list1!=NULL && list2!=NULL){
            ListNode* prev=NULL;
            while(list1!=NULL && list1->val<=list2->val){
                prev=list1;
                list1=list1->next;
            }
            if(prev!=NULL) prev->next=list2;
            swap(list1,list2);
        }
        return root;
    }
};