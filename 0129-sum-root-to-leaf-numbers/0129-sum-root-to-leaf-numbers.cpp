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
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
    
    int helper(TreeNode* node,int sum){
        if(node->left==NULL && node->right==NULL) return sum*10+node->val;
        else{
            return (node->left?helper(node->left,sum*10+node->val):0)+(node->right?helper(node->right,sum*10+node->val):0);
        }
    }
};