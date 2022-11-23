class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        int temp=0;
        bool flag=false;

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(!vis[i][j] && grid[i][j]){
                    flag=false;
                    temp=0;
                    dfs(i,j,grid,vis,flag,temp);
                    if(!flag) ans+=temp;
                }
            }
        }

        return ans;
    }

    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,bool &flag,int &temp){
        int m=grid.size();
        int n=grid[0].size();
        if(i==0 || j==0 || i==m-1 || j==n-1) flag=true;

        vis[i][j]=1;
        temp++;

        if(i-1>=0 && grid[i-1][j]==1 && !vis[i-1][j]) dfs(i-1,j,grid,vis,flag,temp);
        if(i+1<m && grid[i+1][j]==1 && !vis[i+1][j]) dfs(i+1,j,grid,vis,flag,temp);
        if(j-1>=0 && grid[i][j-1]==1 && !vis[i][j-1]) dfs(i,j-1,grid,vis,flag,temp);
        if(j+1<n && grid[i][j+1]==1 && !vis[i][j+1]) dfs(i,j+1,grid,vis,flag,temp); 

    }
};