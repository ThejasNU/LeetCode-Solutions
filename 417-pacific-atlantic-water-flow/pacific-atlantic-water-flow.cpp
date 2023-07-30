class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};

        //visited matrix
        vector<vector<int>> pacific(m,vector<int>(n,0));
        vector<vector<int>> atlantic(m,vector<int>(n,0));

        function<void(int,int)> pacificDFS=[&](int i,int j){
            pacific[i][j]=1;
            for(int k=0;k<4;++k){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<m && y>=0 && y<n && !pacific[x][y] && heights[x][y]>=heights[i][j]){
                    pacificDFS(x,y);
                }
            }
        };

        function<void(int,int)> atlanticDFS=[&](int i,int j){
            atlantic[i][j]=1;
            for(int k=0;k<4;++k){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<m && y>=0 && y<n && !atlantic[x][y] && heights[x][y]>=heights[i][j]){
                    atlanticDFS(x,y);
                }
            }
        };

        for(int i=0;i<n;++i){
            pacificDFS(0,i);
            atlanticDFS(m-1,i);
        }
        for(int i=0;i<m;++i){
            pacificDFS(i,0);
            atlanticDFS(i,n-1);
        }

        vector<vector<int>> ans;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};