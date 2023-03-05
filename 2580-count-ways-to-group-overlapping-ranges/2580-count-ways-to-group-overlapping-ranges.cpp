class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        vector<vector<int>> res=merge(ranges);
        long long n=res.size();
        long long M=1e9+7;
        long long ways=1;
        //2^n because nC0+nC1+....+nCn-1 + nCn=2^n
        while(n--){
            ways=(ways*2)%M;
        }
        return ways%M;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size()==0) return intervals;
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0] <= temp[1]){
                temp[1]=max(intervals[i][1],temp[1]);
            }
            else{
                res.push_back(temp);
                temp=intervals[i];
            }
        }
        res.push_back(temp); 
        return res;
    }
};