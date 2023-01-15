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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        DisjointSet ds(n);
        vector<int> adj[n];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        map<int,vector<int>> valueToNodes;
        for(int i=0;i<n;++i){
            valueToNodes[vals[i]].push_back(i);
        }
        
        //Iterating over all the nodes with the same value in sorted order, starting from the lowest
        int ans=0;
        for(auto it:valueToNodes){
            int value=it.first;
            vector<int> nodes=it.second;
            
            for(int node:nodes){
                for(int neigh:adj[node]){
                    //Taking neighbors with only smaller value
                    if(vals[node]>=vals[neigh]){
                        ds.unionBR(node,neigh);
                    }
                }
            }
            
            unordered_map<int,int> group;
            for(int node:nodes){
                group[ds.find(node)]++;
            }

            for(auto it:group){
                int size=it.second;
                ans+=(size*(size+1)/2);
            }
        }
        return ans;
    }
};