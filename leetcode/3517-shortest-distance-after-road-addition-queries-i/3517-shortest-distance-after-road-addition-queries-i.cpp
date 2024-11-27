class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
        }

        vector<int> ans(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0];
            int v = queries[i][1];

            adj[u].push_back(v);

            ans[i] = helper(n, adj);
        }

        return ans;
    }

    int helper(int n, vector<vector<int>> adj) {
        vector<int> dp(n);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; --i) {
            int minDis = n;
            for (int neigh : adj[i]) {
                minDis = min(minDis, 1 + dp[neigh]);
            }
            dp[i] = minDis;
        }

        return dp[0];
    }
};