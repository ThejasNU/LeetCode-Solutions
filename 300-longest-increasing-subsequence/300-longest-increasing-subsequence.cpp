class Solution {
public:
    
    int lis(int ind,vector<int>&nums,vector<int>&dp){
        if(dp[ind]!=-1) return dp[ind];
        
        int ans=1;
        for(int j=0;j<ind;++j){
            if(nums[ind]>nums[j]) ans=max(ans,lis(j,nums,dp)+1);
        }
        
        return dp[ind]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n,-1);
        
        int res=0;
        for(int i=0;i<n;++i){
            res=max(res,lis(i,nums,dp));
        }
        return res;
    }
};