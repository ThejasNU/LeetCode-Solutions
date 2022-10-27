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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans=helperSmallest(root,k);
        return ans->val;
    }
    
    TreeNode* helperSmallest(TreeNode* node,int &k){
        if(node==NULL) return NULL;
        
        TreeNode* left=helperSmallest(node->left,k);
        if(left!=NULL) return left;
        
        if(--k==0) return node;
        
        return helperSmallest(node->right,k);
    }
    
    TreeNode* helperLargest(TreeNode* node,int &k){
        if(node==NULL) return NULL;
        
        TreeNode* right=helperLargest(node->right,k);
        if(right!=NULL) return right;
        
        if(--k==0) return node;
        
        return helperLargest(node->left,k);
    }

};