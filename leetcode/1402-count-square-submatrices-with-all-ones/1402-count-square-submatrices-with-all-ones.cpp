class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),
                               vector<int>(matrix[0].size(), -1));

        int ans = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                ans += helper(i, j, matrix, dp);
            }
        }

        return ans;
    }

    int helper(int i, int j, vector<vector<int>>& matrix,
               vector<vector<int>>& dp) {
        if (i >= matrix.size() || j >= matrix[0].size()) {
            return 0;
        }

        if (matrix[i][j] == 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = helper(i + 1, j, matrix, dp);
        int right = helper(i, j + 1, matrix, dp);
        int diagonal = helper(i + 1, j + 1, matrix, dp);

        return dp[i][j] = 1 + min({down, right, diagonal});
    }
};