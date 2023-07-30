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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ans=NULL;
        function<void(TreeNode*)> inorder=[&](TreeNode* node){
            if(node==NULL) return;

            inorder(node->left);
            k-=1;
            if(k==0){
                ans=node;
                return;
            }
            inorder(node->right);
        };
        inorder(root);
        return ans->val;
    }
};