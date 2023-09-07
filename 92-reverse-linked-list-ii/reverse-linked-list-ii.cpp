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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return head;
        
        ListNode* startNode = new ListNode(0);
        startNode->next = head;
        
        ListNode* prev = startNode;
        for (int i = 0; i < left-1; i++) {
            prev = prev->next;
        }
        
        ListNode* cur = prev->next;
        ListNode* nxt;
        for (int i = 0; i < right-left; i++) {
            nxt = cur->next;
            cur->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
        }
        
        return startNode->next;
    }
};