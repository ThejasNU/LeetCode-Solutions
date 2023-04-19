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
    int longestZigZag(TreeNode* root) {
        ans=0;
        helper(root,false);
        helper(root,true);
        return ans-1;
    }

    int helper(TreeNode* node,bool goRight){
        if(node==NULL) return 0;
        int c1,c2;
        if(goRight){
            c1=1+helper(node->right,false);
            c2=1+helper(node->left,true);
        }
        else{
            c1=1+helper(node->left,true);
            c2=1+helper(node->right,false);
        }
        ans=max(ans,max(c1,c2));
        return c1;
    }
};