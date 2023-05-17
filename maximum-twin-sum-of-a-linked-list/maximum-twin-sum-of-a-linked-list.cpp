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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=NULL;
        if(slow) fast=slow->next;
        stack<int> st;
        int ans=INT_MIN;
        while(fast!=NULL && fast->next!=NULL){
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        st.push(slow->val);
        slow=slow->next;
        while(slow!=NULL){
            ans=max(st.top()+slow->val,ans);
            st.pop();
            slow=slow->next;
        }
        return ans;
    }
};