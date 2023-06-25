class Solution {
public:
    vector<vector<int>> dp;
    int M=1e9+7;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        dp.resize(n,vector<int>(fuel+1,-1));
        return helper(start,fuel,locations,finish);
    }

    int helper(int cur,int fuelLeft,vector<int>& locations,int finish){
        if(fuelLeft<0) return 0;
        if(dp[cur][fuelLeft]!=-1) return dp[cur][fuelLeft];

        int ans=cur==finish?1:0;
        for(int next=0;next<locations.size();++next){
            if(next!=cur){
                ans=(ans+helper(next,fuelLeft-abs(locations[cur]-locations[next]),locations,finish))%M;
            }
        }
        return dp[cur][fuelLeft]=ans;
    }
};