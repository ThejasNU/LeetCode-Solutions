class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dist[1] = 0;
        q.emplace(0, 1);
        while (!q.empty()) {
            auto [d, curr] = q.top();
            q.pop();
            if (d != dist[curr]) {
                continue;
            }
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1 || dist[curr] + 1 < dist[destination]) {
                    dist[destination] = dist[curr] + 1;
                    q.emplace(dist[destination], destination);
                }
            }
        }
        return dist[n * n];
    }
};