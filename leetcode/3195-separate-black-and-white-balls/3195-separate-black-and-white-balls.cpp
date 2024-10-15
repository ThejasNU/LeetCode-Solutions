class Solution {
public:
    long long minimumSteps(string s) {
        long long blackCount = 0;
        long long ans = 0;
        for (char c : s) {
            if (c == '0') {
                ans += blackCount;
            } else {
                ++blackCount;
            }
        }
        return ans;
    }
};