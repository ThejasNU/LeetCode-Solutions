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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return helper(root,s,k);
    }
    
    bool helper(TreeNode* node,unordered_set<int> &s,int k){
        if(node==NULL) return false;
        if(s.count(k-node->val)) return true;
        
        s.insert(node->val);
        
        return helper(node->left,s,k) || helper(node->right,s,k);
    }
};