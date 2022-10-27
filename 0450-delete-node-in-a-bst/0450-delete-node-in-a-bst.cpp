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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        
        if(root->val==key){
            return helper(root);
        }
        
        TreeNode* newRoot=root;
        while(root!=NULL){
            if(root->val<key){
                if(root->right!=NULL && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
            else{
                if(root->left!=NULL && root->left->val==key){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
        }
        
        return newRoot;
    }
    
    TreeNode* helper(TreeNode* node){
        if(node->left==NULL) return node->right;
        if(node->right==NULL) return node->left;
        
        TreeNode* leftChild=node->left;
        TreeNode* lastLeft=findLastLeft(node->right);
        lastLeft->left=leftChild;
        
        return node->right;
    }
    
    TreeNode* findLastLeft(TreeNode* node){
        if(node->left==NULL) return node;
        
        return findLastLeft(node->left);
    }
};