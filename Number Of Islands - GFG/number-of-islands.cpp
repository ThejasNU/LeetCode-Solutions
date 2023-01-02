//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        int count=0;
        vector<int> ans;
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            
            if(vis[row][col]){
                ans.push_back(count);
                continue;
            }
            
            vis[row][col]=1;
            count++;
            
            for(int i=0;i<4;++i){
                int adjRow=row+dr[i];
                int adjCol=col+dc[i];
                
                if(adjRow<0 || adjCol<0 || adjRow>=n || adjCol>=m) continue;
                
                if(vis[adjRow][adjCol]){
                    int nodeNo=row*m+col;
                    int adjNodeNo=adjRow*m+adjCol;
                    
                    if(ds.find(nodeNo)!=ds.find(adjNodeNo)){
                        count--;
                        ds.unionBR(nodeNo,adjNodeNo);
                    }
                }
            }
            ans.push_back(count);
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends