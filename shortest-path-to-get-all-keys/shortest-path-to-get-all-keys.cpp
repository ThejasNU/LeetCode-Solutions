class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        
        //bit map
        int allKeys=0;
        //row,col,key
        int vis[m][n][65];
        memset(vis,0,sizeof(vis));

        int startRow,startCol;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='@'){
                    startRow=i;
                    startCol=j;
                }
                else if(grid[i][j]>='a' && grid[i][j]<='f'){
                    allKeys |= 1<<(grid[i][j]-'a');
                }
            }
        }

        queue<vector<int>> q;
        //row,col,steps,keys collected
        q.push({startRow,startCol,0,0});

        while(!q.empty()){
            vector<int> cur=q.front();
            q.pop();
            int row=cur[0];
            int col=cur[1];
            int steps=cur[2];
            int keysCollected=cur[3];
            char c=grid[row][col];

            if(c>='a' && c<='f'){
                keysCollected |= 1<<(c-'a');
            }

            if(vis[row][col][keysCollected]) continue;

            vis[row][col][keysCollected]=1;
            if(keysCollected==allKeys) return steps;

            for(int i=0;i<4;++i){
                int nextRow=row+dx[i];
                int nextCol=col+dy[i];

                if(nextRow>=m || nextCol>=n || nextRow<0 || nextCol<0) continue;

                char nextChar=grid[nextRow][nextCol];
                if(nextChar=='#' || vis[nextRow][nextCol][keysCollected]) continue;
                if(nextChar>='A' && nextChar<='F'){
                    int lock=1<<(nextChar-'A');
                    if((keysCollected&lock) == 0) continue;
                }

                q.push({nextRow,nextCol,steps+1,keysCollected});
            }
        }

        return -1;
    }
};













