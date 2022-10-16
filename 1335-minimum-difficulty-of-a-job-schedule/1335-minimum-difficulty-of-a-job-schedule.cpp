class Solution {
public:
    int solve(vector<int> &jd, int idx, int d, vector<vector<int>> &dp){
        int n = jd.size();
        if(idx == n){
            if(d == 0) return 0;
            else return 1e9;
        } 
        if(d <= 0) return 1e9;
        if(dp[idx][d] != -1) return dp[idx][d];
        
        int ans = 1e9,curr = 0;    
        for(int i = idx; i < n; i++){
            curr = max(curr, jd[i]);
            ans = min(ans, curr + solve(jd, i+1, d-1, dp));
        }
        return dp[idx][d] = ans;
    }
    
    
    int minDifficulty(vector<int>& jd, int d) {
        if(d > jd.size()) return -1;
        else if(d == jd.size()){
            int sum = 0;
            for(int i: jd)
                sum += i;
            return sum;
        }
        int n =jd.size();
        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        int ans = solve(jd, 0, d, dp);
        return ans >= 1e9 ? -1 : ans ;
    }
};