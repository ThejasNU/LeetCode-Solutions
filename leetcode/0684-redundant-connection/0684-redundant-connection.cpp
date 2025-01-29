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
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    bool unionBR(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v) {
            return false;
        }

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DisjointSet dsu(n);
        for (vector<int>& edge : edges) {
            if (!dsu.unionBR(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return {};
    }
};