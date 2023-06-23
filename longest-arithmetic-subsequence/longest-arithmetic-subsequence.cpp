class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int diff;
        vector<unordered_map<int,int>> dp(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                diff=nums[i]-nums[j];
                if(dp[j].find(diff)!=dp[j].end()){
                    dp[i][diff]=dp[j][diff]+1;
                }
                else{
                    dp[i][diff]=2;
                }
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};