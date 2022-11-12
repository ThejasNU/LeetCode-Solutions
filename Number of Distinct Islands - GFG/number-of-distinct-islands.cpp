//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] && !vis[i][j]){
                    vector<pair<int,int>> temp;
                    dfs(i,j,i,j,grid,vis,temp);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
    
    void dfs(int i,int j,int baseI,int baseJ,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>> &temp){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        temp.push_back({i-baseI,j-baseJ});
        
        //right,down,left,top
        if(j+1<m && grid[i][j+1] && !vis[i][j+1]) dfs(i,j+1,baseI,baseJ,grid,vis,temp);
        if(i+1<n && grid[i+1][j] && !vis[i+1][j]) dfs(i+1,j,baseI,baseJ,grid,vis,temp);
        if(j-1>=0 && grid[i][j-1] && !vis[i][j-1]) dfs(i,j-1,baseI,baseJ,grid,vis,temp);
        if(i-1>=0 && grid[i-1][j] && !vis[i-1][j]) dfs(i-1,j,baseI,baseJ,grid,vis,temp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends