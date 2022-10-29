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
int ans;
class nodevalue{
    public:
    int minvalue,maxvalue, mxsum;
    nodevalue(int minvalue,int maxvalue,int mxsum){
        this->minvalue=minvalue;
        this->maxvalue=maxvalue;
        this->mxsum=mxsum;
    }
};
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        ans = 0;
        maxSumBSThelper(root);
        return ans >0 ? ans : 0;
    }
private:
    nodevalue maxSumBSThelper(TreeNode* root){
        if(root==NULL)
            return nodevalue(INT_MAX,INT_MIN,0);
        auto left=maxSumBSThelper(root->left);
        auto right=maxSumBSThelper(root->right);
        if(root->val>left.maxvalue && root->val<right.minvalue){
            ans = max(ans, left.mxsum + right.mxsum + root->val);
            return nodevalue(min(root->val,left.minvalue),max(root->val,right.maxvalue),left.mxsum + right.mxsum + root->val);
        }
        return nodevalue(INT_MIN,INT_MAX,max(left.mxsum,right.mxsum));
    }
};