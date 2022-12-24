class Solution {
public:
    int numTilings(int n) {
        int M=1e9+7;
        int dp[1010];
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        
        for(int i=4;i<=n;++i){
            dp[i]= ((2*(dp[i-1]%M)%M)+(dp[i-3]%M))%M;
        }
        
        return dp[n];
    }
};