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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
            
        unordered_map<int,int> m;
        
        for(int i=0;i<inorder.size();++i) m[inorder[i]]=i;
        
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
    }
    
    TreeNode* helper(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe,unordered_map<int,int> &m){
        if(is>ie || ps>pe) return NULL;
        
        TreeNode* root= new TreeNode(postorder[pe]);
        
        int inRoot=m[postorder[pe]];
        int numsLeft=inRoot-is;
        
        root->left=helper(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,m);
        root->right=helper(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,m);
        
        return root;
    }
};