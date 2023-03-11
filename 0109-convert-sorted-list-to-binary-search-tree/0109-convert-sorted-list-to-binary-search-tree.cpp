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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            ++n;
            temp=temp->next;
        }
        return helper(head,n);
    }
    
    TreeNode* helper(ListNode* head,int n){
        if(n==0) return NULL;
        if(n==1) return new TreeNode(head->val);
        
        int mid=n/2;
        ListNode* middleNode=head;
        while(mid--) middleNode=middleNode->next;
        
        TreeNode* newTreeNode=new TreeNode(middleNode->val,helper(head,n/2),helper(middleNode->next,n-1-n/2));
        return newTreeNode;
    }
};