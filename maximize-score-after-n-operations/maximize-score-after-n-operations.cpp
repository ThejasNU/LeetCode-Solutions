class Solution {
public:
    int maxScore(vector<int>& nums) {
        int dpSize=1<<nums.size();
        vector<int> dp(dpSize+1,-1);
        return helper(nums,0,0,dp);
    }

    int helper(vector<int>& nums,int mask,int numPairs,vector<int>& dp){
        if(2*numPairs==nums.size()) return 0;
        if(dp[mask]!=-1) return dp[mask];

        int maxScore=0;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if(((mask>>i)&1)==1 || ((mask>>j)&1)==1) continue;
                int newMask=mask | (1<<i) | (1<<j);
                int curScore=(numPairs+1)*gcd(nums[i],nums[j]);
                maxScore=max(maxScore,curScore+helper(nums,newMask,numPairs+1,dp));
            }
        }
        dp[mask]=maxScore;
        return maxScore;
    }
};