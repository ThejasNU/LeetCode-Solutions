class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        const int MAX_DISTANCE=n+m+1;
        
        //left and top
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]) grid[i][j]=0;
                else{
                    grid[i][j]=min(MAX_DISTANCE, min(i>0?grid[i-1][j]+1:MAX_DISTANCE,j>0?grid[i][j-1]+1:MAX_DISTANCE));
                }
            }
        }
        
        int ans=INT_MIN;
        //right and bottom;
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                grid[i][j]=min(grid[i][j],min(i<n-1?grid[i+1][j]+1:MAX_DISTANCE,j<m-1?grid[i][j+1]+1:MAX_DISTANCE));
                ans=max(ans,grid[i][j]);
            }
        }
        return ans==0||ans==MAX_DISTANCE?-1:ans;
    }
};

class dpSolution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        const int MAX_DISTANCE = rows + cols + 1;
        vector<vector<int>> dist(rows, vector<int> (cols, MAX_DISTANCE));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = min(dist[i][j], min(i > 0 ? dist[i - 1][j] + 1 : MAX_DISTANCE,
                                                     j > 0 ? dist[i][j - 1] + 1 : MAX_DISTANCE));
                }
            }
        }

        int ans = INT_MIN;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                dist[i][j] = min(dist[i][j], min(i < rows - 1 ? dist[i + 1][j] + 1 : MAX_DISTANCE,
                                                 j < cols - 1 ? dist[i][j + 1] + 1 : MAX_DISTANCE));
                
                ans = max(ans, dist[i][j]);
            }
        }
        return ans == 0 || ans == MAX_DISTANCE ? -1 : ans;
    }
};

class bfsSolution {
public:
    const pair<int, int> direction[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int maxDistance(vector<vector<int>>& grid) {
        int visited[grid.size()][grid[0].size()];
        
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                visited[i][j] = grid[i][j];
                if (grid[i][j]) {
                    q.push({i, j});
                }
            }
        }
        
        int distance = -1;
        while (!q.empty()) {
            int qSize = q.size();
            
            while (qSize--) {
                pair<int, int> landCell = q.front();
                q.pop();
                
                for (pair<int, int> dir : direction) {
                    int x = landCell.first + dir.first;
                    int y = landCell.second + dir.second;
                    
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && visited[x][y] == 0) {
                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
            distance++;
        }
        return distance == 0 ? -1 : distance;
    }
};