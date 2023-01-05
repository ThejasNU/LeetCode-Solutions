class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        int ans=1;
        int cur=points[0][1];
        for(int i=1;i<n;++i){
            if(points[i][0]>cur){
                ans++;
                cur=points[i][1];
            }
        }
        
        return ans;
    }
};