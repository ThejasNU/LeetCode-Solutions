class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int alphabet = 26;
        const int mod = 1000000007;
        int m = target.size(), k = words[0].size();
        vector cnt(alphabet, vector<int>(k));
        for (int j = 0; j < k; j++) {
            for (const string& word : words) {
                cnt[word[j] - 'a'][j]++;
            }
        }
        vector dp(m + 1, vector<long long>(k + 1, -1));
        
        function<long long(int, int)> f = [&](int i, int j) -> long long {
            if (j == 0) {
                return i == 0 ? 1 : 0;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            dp[i][j] = f(i, j - 1);
            if (i > 0) {
                dp[i][j] += cnt[target[i - 1] - 'a'][j - 1] * f(i - 1, j - 1);
            }
            dp[i][j] %= mod;
            return dp[i][j];
        };
        
        return f(m, k);
    }
};