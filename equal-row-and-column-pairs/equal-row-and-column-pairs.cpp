class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,vector<int>> rows,cols;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                rows[i].push_back(grid[i][j]);
                cols[j].push_back(grid[i][j]);
            }
        }
        int count=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(rows[i]==cols[j]) ++count;
            }
        }
        return count;
    }
};