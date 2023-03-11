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

// class Solution {
// public:
//     TreeNode* func(ListNode*head,int n){
//         //if we have the length of list 0 then we will simply return the nullptr
//         if(n<=0){
//             return nullptr;
//         }
// 		//if we are remaining with only one length then we will make node of it and return it
//         if(n==1){
//             return new TreeNode(head->val);
//         }
//         int mid=n/2;
//         ListNode* middleNode=head;
// 		//traversing to the mid of the list from head
//         while(mid--){
//             temp=temp->next;
//         }
// 		//then we will get our ans
//         TreeNode*ans=new TreeNode(temp->val,func(head,n/2),func(temp->next,n-n/2-1));
// 		//returning the ans
//         return ans;
        
//     }
//     TreeNode* sortedListToBST(ListNode* head) {
//         if(!head){
//             return nullptr;
//         }
//         int n=0;
// 		//we are calculating the length of the linked list
// 		//so that we can divide the linked list from middle
//         ListNode*temp=head;
//         while(temp){
//             n++;
//             temp=temp->next;
//         }
// 		//then we are calling the function
//         return func(head,n);
//     }
// };