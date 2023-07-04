class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans=helper(0,nums,dp);
        for(int i=1;i<nums.size();++i){
            ans=max(ans,helper(i,nums,dp));
        }
        return ans;
    }

    int helper(int idx,vector<int>& nums,vector<int>& dp){
        if(dp[idx]!=-1) return dp[idx];

        int ans=1;
        for(int i=idx+1;i<nums.size();++i){
            if(nums[i]>nums[idx]) ans=max(ans,1+helper(i,nums,dp));
        }
        return dp[idx]=ans;
    }
};