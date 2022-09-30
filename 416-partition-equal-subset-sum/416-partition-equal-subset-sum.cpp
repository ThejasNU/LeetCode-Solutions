class Solution {
public:
    int dp[210][10010];
    bool func(int i,int sum,vector<int>& nums){
        if(sum==0) return true;
        if(i<0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        //not consider 
        int isPossible=func(i-1,sum,nums);
        //consider
        if(sum-nums[i]>=0) isPossible |= func(i-1,sum-nums[i],nums);
        
        return dp[i][sum]=isPossible;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        
        sum=sum/2;
        return func(nums.size()-1,sum,nums);
    }
};