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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1="";
        string s2="";
        
        dfs(root1,s1);
        dfs(root2,s2);
        
        return s1==s2;
    }
    
    void dfs(TreeNode* node,string &s){
        if(node==NULL) return;
        
        if(node->left==NULL && node->right==NULL){
            s.push_back(node->val+'0');
            s.push_back(',');
        }
        
        if(node->left) dfs(node->left,s);
        if(node->right) dfs(node->right,s);
    }
};