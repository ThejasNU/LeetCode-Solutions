class Solution {
public:
    queue<pair<int,int>> q;
    int dx[4]={0,1,-1,0};
    int dy[4]={1,0,0,-1}; 
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        bool flag=true;
        for(int i=0;i<n;++i){
            for(int j=0;j<n && flag;++j){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis);
                    flag=false;
                    break;
                }
            }
        }

        int ans=0;
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(grid[i][j]==1) return ans;
                for(int k=0;k<4;++k){
                    int x=i+dx[k],y=j+dy[k];
                    if(x>=0 && x<n && y>=0 && y<n && !vis[x][y]){
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            ++ans;
        }
        return ans;
    }

    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || vis[i][j]) return;
        
        if(grid[i][j]==0){
            vis[i][j]=1;
            q.push({i,j});
            return;
        }

        vis[i][j]=1;
        for(int k=0;k<4;++k){
            dfs(i+dx[k],j+dy[k],grid,vis);
        }
    }
};