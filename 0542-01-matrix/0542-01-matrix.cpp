class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> vis(m,vector<int> (n,0));
        vector<vector<int>> dist(m,vector<int> (n));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first.first;
            int y=temp.first.second;
            int d=temp.second;

            dist[x][y]=d;

            if(x-1>=0 && !vis[x-1][y] && mat[x-1][y]==1){
                q.push({{x-1,y},d+1});
                vis[x-1][y]=1;
            } 
            if(x+1<m && !vis[x+1][y] && mat[x+1][y]==1){
                q.push({{x+1,y},d+1});
                vis[x+1][y]=1;
            } 
            if(y-1>=0 && !vis[x][y-1] && mat[x][y-1]==1){
                q.push({{x,y-1},d+1});
                vis[x][y-1]=1;
            } 
            if(y+1<n && !vis[x][y+1] && mat[x][y+1]==1){
                q.push({{x,y+1},d+1});
                vis[x][y+1]=1;
            }
        }

        return dist;
    }
};