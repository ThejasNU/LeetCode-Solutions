class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size() + 1, -1);
        return helper(questions, 0, dp);
    }

    long long helper(vector<vector<int>>& questions, int ind,
                     vector<long long>& dp) {
        if (ind >= questions.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        return dp[ind] =
                   max(questions[ind][0] +
                           helper(questions, ind + questions[ind][1] + 1, dp),
                       helper(questions, ind + 1, dp));
    }
};