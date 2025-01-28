class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!seen[i][j] && grid[i][j] != 0) {
                    seen[i][j] = true;
                    int res = dfs(i, j, grid, seen);
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }

private:
    int dfs(int i, int j, vector<vector<int>>& grid,
            vector<vector<bool>>& seen) {
        int res = grid[i][j];

        if (j - 1 >= 0 && !seen[i][j - 1] && grid[i][j - 1] != 0) {
            seen[i][j - 1] = true;
            res += dfs(i, j - 1, grid, seen);
        }
        if (j + 1 < grid[0].size() && !seen[i][j + 1] && grid[i][j + 1] != 0) {
            seen[i][j + 1] = true;
            res += dfs(i, j + 1, grid, seen);
        }
        if (i - 1 >= 0 && !seen[i - 1][j] && grid[i - 1][j] != 0) {
            seen[i - 1][j] = true;
            res += dfs(i - 1, j, grid, seen);
        }
        if (i + 1 < grid.size() && !seen[i + 1][j] && grid[i + 1][j] != 0) {
            seen[i + 1][j] = true;
            res += dfs(i + 1, j, grid, seen);
        }

        return res;
    }
};