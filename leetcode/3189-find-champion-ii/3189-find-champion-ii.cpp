class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            ++indegree[edge[1]];
        }

        int winner = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                if (winner == -1) {
                    winner = i;
                } else {
                    return -1;
                }
            }
        }

        return winner;
    }
};