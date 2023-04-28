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
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        DisjointSet ds(n);
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                int count=0;
                for(int k=0;k<m;++k){
                    if(strs[i][k]!=strs[j][k]) ++count;
                }
                if(count==2 || count==0){
                    ds.unionBR(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;++i){
            if(ds.find(i)==i) ++ans;
        }
        return ans;
    }
};