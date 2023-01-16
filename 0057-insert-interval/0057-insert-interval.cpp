class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        
        //finding the index to insert using binary search
        int ind=upper_bound(intervals.begin(),intervals.end(),newInterval)-intervals.begin();
        if(ind<n){
            intervals.insert(intervals.begin()+ind,newInterval);   
        }
        else{
            intervals.push_back(newInterval);
        }
        
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