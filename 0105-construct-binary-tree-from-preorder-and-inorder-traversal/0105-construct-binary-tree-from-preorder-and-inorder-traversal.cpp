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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        
        for(int i=0;i<inorder.size();++i){
            m[inorder[i]]=i;
        }
        
        TreeNode* root=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        
        return root;
    }
    
    TreeNode* helper(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int> &m){
        
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode* root=new TreeNode(preorder[preStart]);
        
        int inRoot=m[root->val];
        int numsLeft=inRoot-inStart;
        
        root->left=helper(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,m);
        root->right=helper(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,m);
        
        return root;
    }
};