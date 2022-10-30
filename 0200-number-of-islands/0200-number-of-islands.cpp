class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        count=0;
        
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    count++;
                    erase(i,j,grid);
                } 
            }
        }
        
        return count;
    }

private:
    int count;

    void erase(int i,int j,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        if(i<0||j<0) return;
        if(i>=n||j>=m) return;
        if(grid[i][j]=='0') return;

        grid[i][j]='0';

        erase(i-1,j,grid);
        erase(i+1,j,grid);
        erase(i,j-1,grid);
        erase(i,j+1,grid);
    }
};

