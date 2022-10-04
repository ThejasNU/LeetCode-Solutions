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
    bool helper(TreeNode* node,int remainingSum,int targetSum){
        if(node==NULL ) return false;
        if(remainingSum-node->val==0 && node->left==NULL && node->right==NULL) return true;
        
        return helper(node->left,remainingSum-node->val,targetSum) || helper(node->right,remainingSum-node->val,targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        
        int ans=helper(root,targetSum,targetSum);
        
        return ans;
    }
};