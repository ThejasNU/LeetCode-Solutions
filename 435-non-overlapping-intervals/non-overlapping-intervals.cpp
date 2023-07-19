class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        auto comp=[](vector<int>& v1,vector<int>& v2)->bool{
            return v1[1]<v2[1];
        };
        sort(intervals.begin(),intervals.end(),comp);
        int maxEnd=intervals[0][1];
        int count=0;
        for(int i=1;i<n;++i){
            if(intervals[i][0]<maxEnd){
                count+=1;
            }
            else{
                maxEnd=intervals[i][1];
            }
        }
        return count;
    }
};