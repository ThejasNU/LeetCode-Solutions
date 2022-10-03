class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if(colors=="") return 0;
        
        int time=0;
        int i=0,j=0;
        while(i<colors.size() && j<colors.size()){
            int curTotal=0,curMax=0;
            while(j<colors.size() && colors[i]==colors[j]){
                curTotal+=neededTime[j];
                curMax=max(curMax,neededTime[j]);
                j++;
            }
            time+=curTotal-curMax;
            i=j;
        }
        return time;
    }
};