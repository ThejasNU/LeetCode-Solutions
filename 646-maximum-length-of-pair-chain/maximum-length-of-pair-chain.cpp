class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        
        int n=pairs.size();
        vector<int> dp(n,1);
        
        int ans=1;
        for(int i=n-2;i>=0;--i){
            for(int j=i+1;j<n;++j){
                if(pairs[j][0]>pairs[i][1]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }

};

class topDownSolution {
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