class DisjointSet {
private:
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unionBR(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& queries) {
        DisjointSet dsu(n);
        vector<unsigned int> cost(n, -1);

        for (auto& edge : edges) {
            dsu.unionBR(edge[0], edge[1]);
        }

        for (auto& edge : edges) {
            cost[dsu.find(edge[0])] &= edge[2];
        }

        vector<int> ans;
        for (auto& query : queries) {
            int root1 = dsu.find(query[0]);
            int root2 = dsu.find(query[1]);

            if (root1 != root2) {
                ans.push_back(-1);
            } else {
                ans.push_back(cost[root1]);
            }
        }

        return ans;
    }
};