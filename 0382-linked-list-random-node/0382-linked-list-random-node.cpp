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
    ListNode* root;
    int size;
    Solution(ListNode* head) {
        root=head;
        size=0;
        while(head!=NULL){
            ++size;
            head=head->next;
        }
    }
    
    int getRandom() {
        int num = (rand() %(size)) ;
        ListNode* cur=root;
        int count=0;
        while(count<num){
            ++count;
            cur=cur->next;
        }
        int val=cur->val;
        return val;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */