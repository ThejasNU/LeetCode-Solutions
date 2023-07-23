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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return {};
        unordered_map<int,vector<TreeNode*>> dp;

        function<vector<TreeNode*>(int)> helper=[&](int remaining)->vector<TreeNode*>{
            if(remaining==1){
                return {new TreeNode()};
            }
            if(dp.find(remaining)!=dp.end()) return dp[remaining];

            vector<TreeNode*> ans;
            for(int i=1;i<remaining;i+=2){
                vector<TreeNode*> left=helper(i);
                vector<TreeNode*> right=helper(remaining-i-1);

                for(TreeNode* l:left){
                    for(TreeNode* r:right){
                        TreeNode* root=new TreeNode(0,l,r);
                        ans.push_back(root);
                    }
                }
            }
            return ans;
        };

        return helper(n);
    }
};