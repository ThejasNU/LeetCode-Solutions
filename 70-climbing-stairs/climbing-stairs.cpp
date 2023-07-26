class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n,-1);

        function<int(int)> helper=[&](int stepNum){
            if(stepNum==n) return 1;
            if(stepNum>n) return 0;
            if(dp[stepNum]!=-1) return dp[stepNum];

            return dp[stepNum]=helper(stepNum+1)+helper(stepNum+2);
        };

        return helper(0);
    }
};