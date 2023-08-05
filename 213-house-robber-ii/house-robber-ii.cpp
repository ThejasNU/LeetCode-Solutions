class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];

        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int res1=helper(0,n-2,nums,dp1);
        int res2=helper(1,n-1,nums,dp2);
        return max(res1,res2);
    }

    int helper(int idx,int end,vector<int>& nums,vector<int>& dp){
        if(idx>end) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int notpick=helper(idx+1,end,nums,dp);
        int pick=nums[idx]+helper(idx+2,end,nums,dp);
        return dp[idx]=max(pick,notpick);
    }
};