class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> m;
        int len;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            len = 0;
            for (int j = i; j < s.size(); ++j) {
                if (c == s[j]) {
                    ++len;
                    m[{c, len}] += 1;
                } else {
                    break;
                }
            }
        }

        int ans = -1;
        for (auto& [str, cnt] : m) {
            if (cnt >= 3 && str.second > ans) {
                ans = str.second;
            }
        }
        return ans;
    }
};