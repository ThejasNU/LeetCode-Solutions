class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        function<int(int,int)> helper=[&](int left,int right)->int{
            if(dp[left][right]!=-1) return dp[left][right];
            if(left==right) return nums[left];

            int takeLeft=nums[left]-helper(left+1,right);
            int takeRight=nums[right]-helper(left,right-1);
            return dp[left][right]=max(takeLeft,takeRight);
        };

        return helper(0,n-1)>=0;
    }
};