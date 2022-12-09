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
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        helper(root,root->val,root->val,ans);
        return ans;
    }
    
    void helper(TreeNode* node,int curMin,int curMax,int &ans){
        if(node==NULL) return;

        curMax=max(curMax,node->val);
        curMin=min(curMin,node->val);
        
        ans=max(ans,curMax-curMin);
        
        helper(node->left,curMin,curMax,ans);
        helper(node->right,curMin,curMax,ans);
    }
};