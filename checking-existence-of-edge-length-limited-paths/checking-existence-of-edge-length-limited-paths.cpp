class DisjointSet {
public:
    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0;i<n;i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node]);
    }

    void unionBR(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DisjointSet dsu(n);
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();++i) queries[i].push_back(i);
        sort(edgeList.begin(),edgeList.end(),compare);
        sort(queries.begin(),queries.end(),compare);

        int i=0;
        for(auto q: queries){
            while(i<edgeList.size() && edgeList[i][2]<q[2]){
                dsu.unionBR(edgeList[i][0] , edgeList[i][1]);
                i++;
            }
            
            if(dsu.find(q[0]) == dsu.find(q[1])) ans[q[3]] = true;
        }
        return ans;
    }

    static bool compare(vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    }
};