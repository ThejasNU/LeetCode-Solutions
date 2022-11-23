class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        //i,j,distance
        queue<vector<int>> q;
        int i=entrance[0];
        int j=entrance[1];
        int d;
        vis[i][j]=1;

        if(i-1>=0 && maze[i-1][j]=='.'){
            q.push({i-1,j,1});
            vis[i-1][j]=1;
        } 
        if(i+1<m && maze[i+1][j]=='.'){
            q.push({i+1,j,1});
            vis[i+1][j]=1;
        } 
        if(j-1>=0 && maze[i][j-1]=='.'){
            q.push({i,j-1,1});
            vis[i][j-1]=1;
        } 
        if(j+1<n && maze[i][j+1]=='.'){
            q.push({i,j+1,1});
            vis[i][j+1]=1;
        } 

        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            i=cur[0];
            j=cur[1];
            d=cur[2];

            if(i==0 || j==0 || i==m-1 || j==n-1) return d;

            if(i-1>=0 && maze[i-1][j]=='.' && !vis[i-1][j]){
                q.push({i-1,j,d+1});
                vis[i-1][j]=1;
            } 
            if(i+1<m && maze[i+1][j]=='.' && !vis[i+1][j]){
                q.push({i+1,j,d+1});
                vis[i+1][j]=1;
            } 
            if(j-1>=0 && maze[i][j-1]=='.' && !vis[i][j-1]){
                q.push({i,j-1,d+1});
                vis[i][j-1]=1;
            } 
            if(j+1<n && maze[i][j+1]=='.' && !vis[i][j+1]){
                q.push({i,j+1,d+1});
                vis[i][j+1]=1;
            } 
        }

        return -1;
    }
};