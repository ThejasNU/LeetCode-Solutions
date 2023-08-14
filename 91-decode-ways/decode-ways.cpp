class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return helper(0,s,dp);
    }

    int helper(int idx,const string& s,vector<int>& dp){
        if(idx==s.size()) return 1;
        if(dp[idx]!=-1) return dp[idx];

        int ways=0;
        if(s[idx]!='0'){
            //one digit number
            ways+=helper(idx+1,s,dp);

            //two digits number
            if(idx+1<s.size()){
                int twoDigitNum=stoi(s.substr(idx,2));
                if(twoDigitNum>=0 && twoDigitNum<=26){
                    ways+=helper(idx+2,s,dp);
                }
            }
        }
        return dp[idx]=ways;
    }
};