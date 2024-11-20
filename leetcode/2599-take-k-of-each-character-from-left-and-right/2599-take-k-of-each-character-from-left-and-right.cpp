class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> total(3, 0);

        for (char c : s) {
            ++total[c - 'a'];
        }

        for (int i = 0; i < 3; ++i) {
            if (total[i] < k) {
                return -1;
            }
        }

        vector<int> cur(3, 0);
        int l = 0, extra = 0;
        for (int r = 0; r < n; ++r) {
            ++cur[s[r] - 'a'];
            while (l <= r && (total[0] - cur[0] < k || total[1] - cur[1] < k ||
                              total[2] - cur[2] < k)) {
                --cur[s[l] - 'a'];
                ++l;
            }
            extra = max(extra, r - l + 1);
        }

        return n - extra;
    }
};