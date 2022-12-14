class Solution {
public:
    int dp[110];
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        memset(dp,-1,sizeof(dp));
        int ans=helper(n-1,nums);
        
        return ans;
    }
    
    int helper(int idx,vector<int>& nums){
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int res=max(helper(idx-2,nums)+nums[idx],helper(idx-1,nums));
        
        return dp[idx]=res;
    }
};