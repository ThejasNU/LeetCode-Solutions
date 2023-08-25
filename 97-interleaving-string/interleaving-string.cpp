class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        int n1=s1.size()+1;
        int n2=s2.size()+1;
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return helper(0,0,0,s1,s2,s3,dp);
    }

    bool helper(int idx1,int idx2,int idx3,string& s1,string& s2,string& s3,vector<vector<int>>& dp){
        if(idx3==s3.size()) return 1;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

        bool res=0;
        if(idx1<s1.size() && s1[idx1]==s3[idx3]){
            res|=helper(idx1+1,idx2,idx3+1,s1,s2,s3,dp);
        }

        if(idx2<s2.size() && s2[idx2]==s3[idx3]){
            res|=helper(idx1,idx2+1,idx3+1,s1,s2,s3,dp);
        }

        return dp[idx1][idx2]=res;
    }
};