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
    int ans;
    int longestZigZag(TreeNode* root) {
        ans=0;
        helper(root,false);
        helper(root,true);
        //it counts the nodes, so -- to get edges
        return ans-1;
    }

    int helper(TreeNode* node,bool goRight){
        if(node==NULL) return 0;
        int c1,c2;
        if(goRight){
            //path continued from parent
            c1=1+helper(node->right,false);
            //path which starts at this node
            c2=1+helper(node->left,true);
        }
        else{
            //path continued from parent
            c1=1+helper(node->left,true);
            //path which starts at this node
            c2=1+helper(node->right,false);
        }
        ans=max(ans,max(c1,c2));
        //returning only the value what parent requires, not the path which starts from this node
        return c1;
    }
};