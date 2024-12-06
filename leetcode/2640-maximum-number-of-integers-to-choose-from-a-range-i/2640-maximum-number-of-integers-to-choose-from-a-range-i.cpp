class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());

        int ans = 0;
        int num = 1;
        while (num <= n && maxSum >= num) {
            if (st.find(num) != st.end()) {
                ++num;
                continue;
            }

            ++ans;
            maxSum -= num;
            ++num;
        }

        return ans;
    }
};