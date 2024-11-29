class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int curTime = cur[0], r = cur[1], c = cur[2];

            if (r == m - 1 && c == n - 1) {
                return curTime;
            }

            if (vis[r][c]) {
                continue;
            }

            vis[r][c] = true;

            for (int i = 0; i < 4; ++i) {
                int x = r + dx[i], y = c + dy[i];

                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]) {
                    int extra = ((grid[x][y] - curTime) % 2 == 0) ? 1 : 0;
                    pq.push({max(grid[x][y] + extra, curTime + 1), x, y});
                }
            }
        }

        return -1;
    }
};