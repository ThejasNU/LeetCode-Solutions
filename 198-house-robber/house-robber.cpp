class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        function<int(int)> helper=[&](int idx){
            if(idx>=n) return 0;
            if(dp[idx]!=-1) return dp[idx];

            return dp[idx]=max(nums[idx]+helper(idx+2),helper(idx+1));
        };
        return helper(0);
    }
};