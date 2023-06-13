class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int> rowsCount;
        for(int i=0;i<n;++i){
            rowsCount[grid[i]]+=1;
        } 
        int count=0;
        for(int i=0;i<n;++i){
            vector<int> curCol;
            for(int j=0;j<n;++j){
                curCol.push_back(grid[j][i]);
            }
            count+=rowsCount[curCol];
        }
        return count;
    }
};

class anotherSolution {
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