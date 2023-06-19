class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curAltitude=0;
        int ans=curAltitude;
        for(int i=0;i<gain.size();++i){
            curAltitude+=gain[i];
            ans=max(ans,curAltitude);
        }
        return ans;
    }
};