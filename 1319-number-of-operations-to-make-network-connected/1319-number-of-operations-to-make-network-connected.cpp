class DisjointSet {
public:
    vector<int> parent, size;
    
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for(int i = 0;i<n;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node]);
    }

    void unionBS(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges=0;
        
        for(auto edge:connections){
            int u=edge[0];
            int v=edge[1];
            
            if(ds.find(u)==ds.find(v)) extraEdges++;
            else ds.unionBS(u,v);
        }
        
        int numComponents=0;
        for(int i=0;i<n;++i){
            if(ds.parent[i]==i) numComponents++;
        }
        
        if(extraEdges>=numComponents-1) return numComponents-1;
        else return -1;
    }
};