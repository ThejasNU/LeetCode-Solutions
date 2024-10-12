class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int start = INT_MAX, end = INT_MIN;
        for (auto& interval : intervals) {
            start = min(start, interval[0]);
            end = max(end, interval[1]);
        }

        vector<int> count(end + 2, 0);
        for (auto& interval : intervals) {
            count[interval[0]] += 1;
            count[interval[1] + 1] -= 1;
        }

        int cur = 0;
        int ans = 0;
        for (int i = start; i <= end; ++i) {
            cur += count[i];
            ans = max(ans, cur);
        }

        return ans;
    }
};