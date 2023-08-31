class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n+1);

        for(int i=0;i<ranges.size();++i){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            maxReach[start]=max(maxReach[start],end);
        }

        int taps=0;
        int curPoint=0;
        int nextPoint=0;
        for(int i=0;i<=n;++i){
            if(i>nextPoint){
                return -1;
            }
            if(i>curPoint){
                taps+=1;
                curPoint=nextPoint;
            }
            nextPoint=max(nextPoint,maxReach[i]);
        }
        return taps;
    }
};