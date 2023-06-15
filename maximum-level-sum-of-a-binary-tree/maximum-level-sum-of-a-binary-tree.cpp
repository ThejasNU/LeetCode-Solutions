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
    int maxLevelSum(TreeNode* root) {
        long long maxScore=INT_MIN*1ll-10*1ll;
        long long ans;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        while(!q.empty()){
            long long levelSum=0;
            long long numLevelElements=q.size();
            while(numLevelElements--){
                TreeNode* cur=q.front();
                q.pop();
                levelSum+=cur->val*1ll;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            if(levelSum>maxScore){
                maxScore=levelSum;
                ans=level;
            }
            ++level;
        }
        return ans;
    }
};