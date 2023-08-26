class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        
        int n=pairs.size();
        vector<int> dp(n,-1);
        dp[n-1]=1;
        
        helper(0,pairs,dp);
        
        return *max_element(dp.begin(),dp.end());
    }

    int helper(int idx,vector<vector<int>>& pairs,vector<int>& dp){
        if(dp[idx]!=-1) return dp[idx];
        
        int res=1;
        
        //ignore
        res=max(res,helper(idx+1,pairs,dp));

        //take
        for(int next=idx+1;next<pairs.size();++next){
            if(pairs[next][0]<=pairs[idx][1]) continue;

            res=max(res,1+helper(next,pairs,dp));
        }
        
        return dp[idx]=res;
    }
};