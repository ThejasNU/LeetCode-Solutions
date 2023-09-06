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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* cur=head;
        while(cur!=NULL){
            cur=cur->next;
            n++;
        }

        int nodesPerPartition=n/k,extra=n%k;
        vector<ListNode*> ans;
        cur=head;
        ListNode* prev=NULL;
        for(int i=0;i<k;++i){
            ans.push_back(cur);

            for(int j=0;j<nodesPerPartition;j++){
                prev=cur;
                cur=cur->next;
            }

            if(extra>0){
                prev=cur;
                cur=cur->next;
                extra--;
            }

            if(prev){
                prev->next=NULL;
                prev=NULL;
            }
        }

        return ans;
    }
};