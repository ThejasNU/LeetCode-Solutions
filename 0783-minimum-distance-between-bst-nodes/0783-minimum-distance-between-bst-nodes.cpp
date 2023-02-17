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
    int ans;
    TreeNode* prev;
    int minDiffInBST(TreeNode* root) {
        ans=INT_MAX;
        prev=NULL;
        inorder(root);
        return ans;
    }
    
    void inorder(TreeNode* node){
        if(node==NULL) return;
        
        inorder(node->left);
        if(prev!=NULL){
            ans=min(ans,node->val-prev->val);
        }
        prev=node;
        inorder(node->right);
    }
};