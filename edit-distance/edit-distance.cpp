class Solution {
public:
    int dp[501][501];
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,word1,word2);
    }

    int helper(int idx1,int idx2,const string& word1,const string& word2){
        if(idx1==word1.size()) return word2.size()-idx2;
        if(idx2==word2.size()) return word1.size()-idx1;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        int ans;
        if(word1[idx1]==word2[idx2]){
            ans=helper(idx1+1,idx2+1,word1,word2);
        }
        else{
            //replace
            ans=1+helper(idx1+1,idx2+1,word1,word2);
            //delete
            ans=min(ans,1+helper(idx1+1,idx2,word1,word2));
            //insert
            ans=min(ans,1+helper(idx1,idx2+1,word1,word2));
        }
        
        return dp[idx1][idx2]=ans;
    }
};