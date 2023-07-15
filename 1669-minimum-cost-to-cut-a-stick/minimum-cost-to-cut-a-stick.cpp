class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return helper(1,cuts.size()-2,cuts,dp);
    }

    int helper(int left, int right, vector<int> &cuts,  vector<vector<int>> &dp){
        if(left>right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];

        int ans=INT_MAX;
        for(int idx=left;idx<=right;++idx){
            ans=min(ans,cuts[right+1]-cuts[left-1]+helper(left,idx-1,cuts,dp)+helper(idx+1,right,cuts,dp));
        }
        return dp[left][right]=ans;
    }
};