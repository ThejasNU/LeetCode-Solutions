class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        int height = 1;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto cur = q.front();
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int x = cur.first + dx[i], y = cur.second + dy[i];

                    if (x >= 0 && x < m && y >= 0 && y < n && ans[x][y] == -1) {
                        ans[x][y] = height;
                        q.push({x, y});
                    }
                }
            }
            ++height;
        }

        return ans;
    }
};