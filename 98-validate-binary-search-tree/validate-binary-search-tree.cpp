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
    bool isValidBST(TreeNode* root) {
        
        function<bool(TreeNode*,long,long)> helper=[&](TreeNode* node,long min,long max)->bool{
            if(node==NULL) return true;

            if(node->val>min && node->val<max){
                bool res1=helper(node->left,min,node->val);
                bool res2=helper(node->right,node->val,max);
                return res1&&res2;
            } 
            else return false;
        };

        return helper(root,LONG_MIN,LONG_MAX);
    }
};