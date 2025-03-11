class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> m;
        int ans = 0;
        int l = 0, r = 0;

        for (; r < s.size(); ++r) {
            ++m[s[r]];

            for (; m.size() == 3; ++l) {
                ans += s.size() - r;
                if (--m[s[l]] == 0) {
                    m.erase(s[l]);
                }
            }
        }

        return ans;
    }
};