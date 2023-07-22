class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        double dp[n][n][k+1];
        memset(dp,0,sizeof(dp));
        int dx[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
        int dy[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };

        function<double(int,int,int)> helper = [&](int i,int j,int movesLeft)->double{
            if(i<0 || j<0 || i>=n || j>=n) return 0;
            if(movesLeft==0) return 1;
            if(dp[i][j][movesLeft]!=0) return dp[i][j][movesLeft];

            double ans=0;
            for(int x=0;x<8;++x){
                int newR=i+dx[x];
                int newC=j+dy[x];
                ans+=helper(newR,newC,movesLeft-1);
            }
            return dp[i][j][movesLeft]=(ans/8.0);
        };

        return helper(row,column,k);
    }
};