class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;++i){
            sort(grid[i].begin(),grid[i].end(),greater<>());
        }
        
        int ans=0;
        //columns
        for(int i=0;i<n;++i){
            int maxi=INT_MIN;
            
            //rows
            for(int j=0;j<m;++j){
                maxi=max(maxi,grid[j][i]);
            }
            // cout<<maxi<<endl;
            ans+=maxi;
        }
        
        return ans;
    }
};