class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans=1;
        for(int num:arr){
            int beforeNum=dp.find(num-difference)!=dp.end()?dp[num-difference]:0;
            dp[num]=beforeNum+1;
            ans=max(ans,dp[num]);
        }
        return ans;
    }
};