class Solution {
    //let's take [-2,5,4,-1],after sorting -> (5*1,5*2+2*1,5*3+2*2+-1*1,5*4+2*3+-1*2+-2*1), we can rewrite it as prefixSum[0],prefixSum[1]+prefixSum[0],prefixSum[2]+prefixSum[1]+prefixSum[0],prefixSum[4]+prefixSum[2]+prefixSum[1]+prefixSum[0]
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end(),greater<int>());
        
        vector<int> prefixSum=satisfaction;
        for(int i=1;i<n;++i){
            prefixSum[i]+=prefixSum[i-1];
        }

        int ans=0,count=0;
        for(int i=0;i<n;++i){
            count+=prefixSum[i];
            ans=max(ans,count);
        }
        return ans;
    }
};