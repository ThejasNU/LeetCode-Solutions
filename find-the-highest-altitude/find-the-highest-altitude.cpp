class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=max(0,gain[0]);
        int sum=gain[0];
        for(int i=1;i<gain.size();++i){
            sum+=gain[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};