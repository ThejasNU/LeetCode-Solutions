class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int maxEnd = 0, ans = 0;
        for (auto& meeting : meetings) {
            if (meeting[0] > maxEnd + 1) {
                ans += meeting[0] - maxEnd - 1;
            }
            maxEnd = max(meeting[1], maxEnd);
        }
        ans += days - maxEnd;
        return ans;
    }
};