class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        
        int cur = 1;
        int idx = 0;
        
        for (int i = 0; i < n; ++i) {
            ans[idx] = cur;
            ++idx;

            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                while (cur % 10 == 9 || cur >= n) {
                    cur /= 10;
                }
                cur += 1;
            }
        }
        
        return ans;
    }
};