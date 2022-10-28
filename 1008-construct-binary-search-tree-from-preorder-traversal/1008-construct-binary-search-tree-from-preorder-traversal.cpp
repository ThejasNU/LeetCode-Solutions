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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        int n=preorder.size();
        
        TreeNode* root=new TreeNode(preorder[0]);
        
        for(int i=1;i<n;++i){
            TreeNode* cur=root;
            while(cur!=NULL){
                if(cur->val<preorder[i]){
                    if(cur->right) cur=cur->right;
                    else{
                        cur->right=new TreeNode(preorder[i]);
                        break;
                    }
                }
                else{
                    if(cur->left) cur=cur->left;
                    else{
                        cur->left=new TreeNode(preorder[i]);
                        break;
                    }
                }
            }
        }
        
        return root;
    }
};