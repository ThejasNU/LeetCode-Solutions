class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        int ind=0;
        while(ind<n && intervals[ind][0]<newInterval[0]) ind++;
        
        intervals.insert(intervals.begin()+ind,newInterval);
        
        vector<vector<int>> ans;
        vector<int> temp=intervals[0];
        for(int i=1;i<=n;++i){
            if(intervals[i][0]<=temp[1]){
                temp[1]=max(temp[1],intervals[i][1]);
            }
            else{
                ans.push_back(temp);
                temp=intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};