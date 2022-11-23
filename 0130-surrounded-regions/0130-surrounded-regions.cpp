class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        //iterating last rows
        for(int i=0;i<n;++i){
            if(!vis[0][i] && board[0][i]=='O') dfs(0,i,board,vis,m,n);
            if(!vis[m-1][i] && board[m-1][i]=='O') dfs(m-1,i,board,vis,m,n);
        }

        //iterating last columns
        for(int i=0;i<m;++i){
            if(!vis[i][0] && board[i][0]=='O') dfs(i,0,board,vis,m,n);
            if(!vis[i][n-1] && board[i][n-1]=='O') dfs(i,n-1,board,vis,m,n);
        }

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }

    void dfs(int x,int y,vector<vector<char>>& board,vector<vector<int>>& vis,int m,int n){
        vis[x][y]=1;

        if(x-1>=0 && board[x-1][y]=='O' && !vis[x-1][y]) dfs(x-1,y,board,vis,m,n);
        if(x+1<m && board[x+1][y]=='O' && !vis[x+1][y]) dfs(x+1,y,board,vis,m,n);
        if(y-1>=0 && board[x][y-1]=='O' && !vis[x][y-1]) dfs(x,y-1,board,vis,m,n);
        if(y+1<n && board[x][y+1]=='O' && !vis[x][y+1]) dfs(x,y+1,board,vis,m,n);
    }
};