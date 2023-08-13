class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool> dp;
        return helper(0,nums,dp);
    }

    bool helper(int idx,vector<int>& nums,unordered_map<int,bool>& dp){
        int n=nums.size();
        if(idx==n) return true;
        if(dp.find(idx)!=dp.end()) return dp[idx];

        bool ans=false;
        if(idx+1<n && nums[idx]==nums[idx+1]){
            ans|=helper(idx+2,nums,dp);
        }

        if(idx+2<n && nums[idx]==nums[idx+1] && nums[idx+1]==nums[idx+2]){
            ans|=helper(idx+3,nums,dp);
        }

        if(idx+2<n && (nums[idx]==(nums[idx+1]-1)) && (nums[idx+1]==(nums[idx+2]-1))){
            ans|=helper(idx+3,nums,dp);
        }

        return dp[idx]=ans;
    }
};