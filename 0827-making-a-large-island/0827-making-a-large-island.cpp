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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        
        for(int row=0;row<n;++row){
            for(int col=0;col<n;++col){
                if(grid[row][col]==0) continue;
                
                for(int i=0;i<4;++i){
                    int newr=row+dr[i];
                    int newc=col+dc[i];
                    
                    if(newr<0 || newc<0 || newr>=n || newc>=n) continue;
                    
                    if(grid[newr][newc]){
                        int nodeNo=row*n+col;
                        int adjNodeNo=newr*n+newc;
                        ds.unionBS(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        
        int maxi=0;
        for(int row=0;row<n;++row){
            for(int col=0;col<n;++col){
                if(grid[row][col]==1) continue;
                set<int> components;
                for(int i=0;i<4;++i){
                    int newr=row+dr[i];
                    int newc=col+dc[i];
                    
                    if(newr<0 || newc<0 || newr>=n || newc>=n) continue;
                    
                    if(grid[newr][newc]){
                        int adjNodeNo=newr*n+newc;
                        components.insert(ds.find(adjNodeNo));
                    }
                }
                
                int sizeTotal=0;
                for(auto it:components){
                    sizeTotal+=ds.size[it];
                }
                maxi=max(sizeTotal+1,maxi);
            }
        }
        
        //if all components are connected
        maxi=max(maxi,ds.size[ds.find(0)]);
        return maxi;
    }
};