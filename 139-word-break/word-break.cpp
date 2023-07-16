class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        return helper(0,s,wordDict,dp);
    }

    bool helper(int idx,const string& s, vector<string>& wordDict,vector<int>& dp){
        if(idx>=s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];

        for(string word:wordDict){
            int wordSize=word.size();
            if(idx+wordSize-1>=s.size()) continue;

            if(s.substr(idx,wordSize)==word && helper(idx+wordSize,s,wordDict,dp)){
                return dp[idx]=1;
            }
        }

        return dp[idx]=0;
    }
};