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
    bool isValidBST(TreeNode* root) {
        // if(root==NULL || (root->left==NULL&&root->right==NULL)) return true;
        return helper(root,INT_MIN*2ll,INT_MAX*2ll);
    }
    
    bool helper(TreeNode* node,long long low,long long high){
        if(node==NULL) return true;
        
        if(node->val>=high || node->val<=low) return false;
        
        return helper(node->left,low,node->val) && helper(node->right,node->val,high);
    }
    
};