class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> times;
        for(auto& event:events){
            times.push_back({event[0],1,event[2]});
            times.push_back({event[1]+1,0,event[2]});
        }

        sort(times.begin(),times.end());
        
        int ans=0,maxVal=0;
        for(auto& time:times){
            if(time[1]){
                ans=max(ans,time[2]+maxVal);
            } else{
                maxVal=max(maxVal,time[2]);
            }
        }

        return ans;
    }
};