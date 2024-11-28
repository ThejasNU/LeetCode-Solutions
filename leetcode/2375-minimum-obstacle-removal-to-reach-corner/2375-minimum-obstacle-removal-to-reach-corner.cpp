class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> minObs(m, vector<int>(n, INT_MAX));
        minObs[0][0] = 0;

        deque<array<int, 3>> dq;
        dq.push_back({0, 0, 0});

        while (!dq.empty()) {
            auto cur = dq.front();
            dq.pop_front();
            int row = cur[0], col = cur[1], obs = cur[2];

            for (auto& dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    minObs[newRow][newCol] == INT_MAX) {
                    if (grid[newRow][newCol] == 1) {
                        minObs[newRow][newCol] = obs + 1;
                        dq.push_back({newRow, newCol, obs + 1});
                    } else {
                        minObs[newRow][newCol] = obs;
                        dq.push_front({newRow, newCol, obs});
                    }
                }
            }
        }

        return minObs[m - 1][n - 1];
    }
};