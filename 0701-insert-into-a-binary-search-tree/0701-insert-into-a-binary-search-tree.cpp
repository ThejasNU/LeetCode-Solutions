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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* newRoot=new TreeNode(val);
            return newRoot;
        }
        
        TreeNode* newRoot=root;
        while(root!=NULL){
            if(root->val > val){
                if(root->left==NULL){
                    TreeNode* temp=new TreeNode(val);
                    root->left=temp;
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right==NULL){
                    TreeNode* temp=new TreeNode(val);
                    root->right=temp;
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        
        return newRoot;
        
    }
};