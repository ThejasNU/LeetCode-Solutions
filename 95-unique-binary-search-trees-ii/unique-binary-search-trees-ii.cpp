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
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>,vector<TreeNode*>> dp;
        return helper(1,n,dp);
    }

    vector<TreeNode*> helper(int start,int end,map<pair<int,int>,vector<TreeNode*>>& dp){
        if(start>end) return {NULL};
        if(dp.find({start,end})!=dp.end()) return dp[{start,end}];

        vector<TreeNode*> res;
        for(int i=start;i<=end;++i){
            vector<TreeNode*> leftSubTrees=helper(start,i-1,dp);
            vector<TreeNode*> rightSubTrees=helper(i+1,end,dp);

            for(TreeNode* left:leftSubTrees){
                for(TreeNode* right:rightSubTrees){
                    res.push_back(new TreeNode(i,left,right));
                }
            }
        }
        return res;
    }
};