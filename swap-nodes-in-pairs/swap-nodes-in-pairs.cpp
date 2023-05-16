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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p1=head;
        ListNode* p2=(p1?p1->next:NULL);
        return helper(p1,p2);
    }

    ListNode* helper(ListNode* p1,ListNode* p2){
        if(!p2 && p1) return p1;
        else if(!p1 && !p2) return NULL;
        
        p1->next=helper(p2->next,(p2->next?p2->next->next:NULL));
        p2->next=p1;
        return p2;
    }
};