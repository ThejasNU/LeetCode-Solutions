class Solution {
public:
    int M=1000000007;
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(),-1);
        return helper(s,k,0,dp);
    }

    int helper(const string& s,long long k,int start,vector<int>& dp){
        if(start==s.size()) return 1;
        if(s[start]=='0') return 0;
        if(dp[start]!=-1) return dp[start];

        int count=0;
        long long num = 0;
        for(int end=start;end<s.size();++end){
            num = num * 10 + s[end]-'0';
            if(num>k) break;
            count+=helper(s,k,end+1,dp);
            count%=M;
        }
        return dp[start]=count;
    }
};