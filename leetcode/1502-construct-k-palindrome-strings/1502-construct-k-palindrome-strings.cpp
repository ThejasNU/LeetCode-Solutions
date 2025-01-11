class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }

        unordered_map<char, int> m;
        for (char c : s) {
            m[c] += 1;
        }

        int oddCnt = 0;
        for (auto& [c, cnt] : m) {
            if (cnt & 1) {
                oddCnt++;
            }
        }

        return oddCnt <= k;
    }
};