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
    int minDepth(TreeNode* root) {
        ans=INT_MAX;
        helper(root,1);
        return ans==INT_MAX?0:ans;
    }

    void helper(TreeNode* node,int count){
        if(!node) return;
        if(!node->left && !node->right){
            ans=min(ans,count);
            return;
        }

        helper(node->left,count+1);
        helper(node->right,count+1);
    }
};