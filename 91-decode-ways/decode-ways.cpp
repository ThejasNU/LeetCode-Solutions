// class Solution { // 12 ms, faster than 9.19%
// public:
//     int memo[100] = {};
//     int numDecodings(const string& s) {
//         return dp(s, 0);
//     }
//     int dp(const string& s, int i) {
//         if (i == s.size()) return 1;
//         if (memo[i] != 0) return memo[i];
//         int ans = 0;
//         if (s[i] != '0') // Single digit
//             ans += dp(s, i+1);
//         if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
//             ans += dp(s, i+2);
//         return memo[i] = ans;
//     }
// };

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
            ways+=helper(idx+1,s,dp);

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