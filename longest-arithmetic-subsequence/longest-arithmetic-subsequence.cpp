class Solution {
public:
    //max diff possible is 500 and min diff possible is -500
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int diff;
        vector<vector<int>> dp(n,vector<int>(1001,1));
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                //add 500 to avoid negative index
                diff=500+nums[i]-nums[j];
                dp[i][diff]=dp[j][diff]+1;
                ans=max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};

class mapSolution {
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