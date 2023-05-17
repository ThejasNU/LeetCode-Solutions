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

 //reversing the 2nd half of the linked list;
class Solution{
public:
    int pairSum(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=NULL;
        if(slow) fast=slow->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        slow=slow->next;
        ListNode *nextNode,*prev=NULL;
        while(slow!=NULL){
            nextNode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextNode;
        }
        int ans=INT_MIN;
        ListNode* start=head;
        //now prev has the head of the reversed linked list
        while(prev){
            ans=max(start->val+prev->val,ans);
            prev=prev->next;
            start=start->next;
        }
        return ans;
    }
};

class stackSolution {
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