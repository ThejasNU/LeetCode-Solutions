class DisjointSet {
public:
    vector<long long> parent, size;

    DisjointSet(long long n) {
        parent.resize(n);
        size.resize(n);
        for(long long i = 0;i<n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    long long find(long long node) {
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node]);
    }

    void unionBS(long long u, long long v) {
        long long ulp_u = find(u);
        long long ulp_v = find(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet dsu(n);
        for(auto& edge:edges){
            dsu.unionBS(edge[0],edge[1]);
        }
        
        vector<long long> sizes;
        for(long long i=0;i<n;++i){
            if(dsu.find(i)==i) sizes.push_back(dsu.size[i]);
        }
        
        long long ans=0;
        long long remainingNodes=n;
        if(sizes.size()>1){
            for(int i=0;i<sizes.size();++i){
                remainingNodes-=sizes[i];
                ans+=sizes[i]*remainingNodes;
            }
        }
        return ans;
    }
};