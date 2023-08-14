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
        return helper(0,preorder.size()-1,preorder,0,inorder.size()-1,inorder);
    }

    TreeNode* helper(int ps,int pe,vector<int>& preorder,int is,int ie,vector<int>& inorder){
        if(is>ie || ps>pe) return NULL;
        
        int nodeVal=preorder[ps];
        TreeNode* node=new TreeNode(nodeVal);
        int idx=is;
        while(idx<=ie && nodeVal!=inorder[idx]) idx+=1;
        int leftSubtreeSize=idx-is;
        node->left=helper(ps+1,ps+leftSubtreeSize,preorder,is,idx-1,inorder);
        node->right=helper(ps+leftSubtreeSize+1,pe,preorder,idx+1,ie,inorder);
        return node;
    }
};