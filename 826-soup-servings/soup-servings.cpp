class Solution {
public:
    double soupServings(int n) {
        int m=ceil(n/25.0);
        unordered_map<int,unordered_map<int,double>> dp;

        function<double(int,int)> helper=[&](int a,int b)->double{
            if(a<=0 && b<=0) return 0.5;
            if(a<=0) return 1.0;
            if(b<=0) return 0.0;
            if(dp[a].count(b)) return dp[a][b];

            return dp[a][b]=(helper(a-4,b)+helper(a-3,b-1)+helper(a-2,b-2)+helper(a-1,b-3))*0.25;
        };

        for(int i=1;i<=m;++i){
            if(helper(i,i)>1-1e-5) return 1.0;
        }

        return helper(m,m);
    }
};