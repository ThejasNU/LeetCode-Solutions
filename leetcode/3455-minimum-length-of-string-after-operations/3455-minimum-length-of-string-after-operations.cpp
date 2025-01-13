class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int ans = 0;
        for (int cnt : freq) {
            if (cnt == 0) {
                continue;
            }

            if (cnt % 2 == 0) {
                ans += 2;
            } else {
                ans += 1;
            }
        }

        return ans;
    }
};