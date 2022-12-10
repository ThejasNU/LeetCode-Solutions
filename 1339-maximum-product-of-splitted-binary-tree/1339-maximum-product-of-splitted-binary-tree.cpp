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
    int totalSum;
    int M=1e9+7;
    
    int maxProduct(TreeNode* root) {
        totalSum=findSum(root);
        long long ans=INT_MIN;
        helper(root,ans);
        
        return ans%M;
    }
    
    int findSum(TreeNode* node){
        if(node==NULL) return 0;
        return node->val+findSum(node->left)+findSum(node->right);
    }
    
    int helper(TreeNode* node,long long &ans){
        if(node==NULL) return 0;
        
        int curSubtreeSum=node->val+helper(node->left,ans)+helper(node->right,ans);
        ans=max(ans,(totalSum-curSubtreeSum)*1ll*curSubtreeSum);
        
        return curSubtreeSum;
    }
};