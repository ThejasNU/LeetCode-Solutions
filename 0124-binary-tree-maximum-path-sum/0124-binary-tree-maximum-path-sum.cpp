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
    int find(TreeNode* node,int &maxi){
        if(node==NULL) return 0;
        
        //To avoid negative numbers
        int ls=max(0,find(node->left,maxi));
        int rs=max(0,find(node->right,maxi));
        
        maxi=max(maxi,ls+rs+node->val);
        
        return node->val+max(ls,rs);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        find(root,maxi);
        return maxi;
    }
};