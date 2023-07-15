class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        sum/=2;
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return helper(0,nums,sum,dp);
    }

    bool helper(int idx,vector<int>& nums,int sumLeft,vector<vector<int>>& dp){
        if(sumLeft==0) return true;
        if(idx>=nums.size()) return false;
        if(dp[idx][sumLeft]!=-1) return dp[idx][sumLeft];

        //not take
        bool ans=helper(idx+1,nums,sumLeft,dp);
        //take
        if(sumLeft>=nums[idx]) ans|=helper(idx+1,nums,sumLeft-nums[idx],dp);

        return dp[idx][sumLeft]=ans;
    }
};