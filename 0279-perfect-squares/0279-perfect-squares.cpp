class Solution {
public:
    static const int N=1e4+10;
    int dp[N];

    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        helper(n);
        return dp[n];
    }

    int helper(int target){
        if(target==0) return 0;
        if(dp[target]!=-1) return dp[target];

        int count=INT_MAX;
        for(int i=1;i<=sqrt(target);++i){
            int square=pow(i,2);

            if(target-square>=0) count=min(count,1+helper(target-square));
        }

        return dp[target]=count;
    }
};