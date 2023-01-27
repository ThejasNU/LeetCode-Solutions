class Solution {
public:
    int dp[110];
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(s);
        return ans;
    }
    
    int helper(string s){
        if(s=="") return 1;
        if(dp[s.size()]!=-1) return dp[s.size()];
        
        int ways=0;
        if(s[0]-'0'>0 && s[0]-'0'<27) ways+=helper(s.substr(1));
        if(s.size()>1 && s[0]!='0' && stoi(s.substr(0,2))>0 && stoi(s.substr(0,2))<27) ways+=helper(s.substr(2));
        return dp[s.size()]=ways;
    }
};