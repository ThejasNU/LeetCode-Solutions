class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        int i=m-1;
        int j=0;
        while(i>=0){
            while(j<n && grid[i][j]>=0) ++j;
            count+=n-j;
            --i;
        }
        return count;
    }
};