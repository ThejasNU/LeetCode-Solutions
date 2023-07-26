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
    TreeNode* invertTree(TreeNode* root) {
        function<void(TreeNode*)> helper=[&](TreeNode* node)->void{
            if(node==NULL) return;
            helper(node->left);
            helper(node->right);
            swap(node->left,node->right);
        };

        helper(root);
        return root;
    }
};