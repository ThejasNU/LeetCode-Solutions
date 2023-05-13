class Solution {
public:
    int M=1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        int ans=0;
        for(int size=low;size<=high;++size){
            ans+=helper(size,zero,one,dp);
            ans%=M;
        }
        return ans;
    }

    int helper(int size,int zero,int one,vector<int>& dp){
        if(size==0) return 1;
        if(dp[size]!=-1) return dp[size];

        int count=0;

        if(size>=zero) count+=helper(size-zero,zero,one,dp);
        if(size>=one) count+=helper(size-one,zero,one,dp);

        return dp[size]=count%M;
    }
};