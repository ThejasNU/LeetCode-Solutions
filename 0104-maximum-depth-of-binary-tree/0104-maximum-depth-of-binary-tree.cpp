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
    int maxDepth(TreeNode* root) {
        ans=0;
        dfs(root,0);
        return ans;
    }
    
    void dfs(TreeNode* node,int cur){
        if(node==NULL){
            ans=max(ans,cur);
            return;
        }
        dfs(node->left,cur+1);
        dfs(node->right,cur+1);
        return;
    }
};

class oldSolution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return 1+max(lh,rh);
    }
};