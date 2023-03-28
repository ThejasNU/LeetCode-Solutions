class Solution {
public:
    int dp[1010];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return helper(days,costs,0);
    }

    int helper(vector<int>& days, vector<int>& costs,int idx){
        int n=days.size();
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int option1=costs[0]+helper(days,costs,idx+1);

        int i=idx;
        while(i<n && days[i]<days[idx]+7) ++i;
        int option2=costs[1]+helper(days,costs,i);

        i=idx;
        while(i<n && days[i]<days[idx]+30) ++i;
        int option3=costs[2]+helper(days,costs,i);

        return dp[idx]=min(option1,min(option2,option3));
    }
};