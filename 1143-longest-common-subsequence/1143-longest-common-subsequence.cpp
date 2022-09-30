class Solution {
public:
    int dp[1010][1010];
    
    int lcs(int i,int j,string &text1,string &text2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        // remove 1 char from text1
        int ans=lcs(i-1,j,text1,text2);
        
        //remove 1 char from text2
        ans=max(ans,lcs(i,j-1,text1,text2));
        
        //remove 1 char from both and compare
        ans=max(ans,lcs(i-1,j-1,text1,text2)+(text1[i]==text2[j]));
        
        return dp[i][j]=ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return lcs(text1.size()-1,text2.size()-1,text1,text2);
    }
};