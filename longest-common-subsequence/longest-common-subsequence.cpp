class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,text1,text2);
    }

    int helper(int idx1,int idx2,const string& text1,const string& text2){
        if(idx1==text1.size() || idx2==text2.size()) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        int ans;
        ans=helper(idx1+1,idx2,text1,text2);
        ans=max(ans,helper(idx1,idx2+1,text1,text2));
        if(text1[idx1]==text2[idx2]) ans=max(ans,1+helper(idx1+1,idx2+1,text1,text2));
        return dp[idx1][idx2]=ans;
    }
};