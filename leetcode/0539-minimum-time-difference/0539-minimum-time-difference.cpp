class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> present(24 * 60, false);
        int hours, mins, convMins;
        for (const string& time : timePoints) {
            hours = stoi(time.substr(0, 2));
            mins = stoi(time.substr(3));
            convMins = hours * 60 + mins;

            if (present[convMins]) {
                return 0;
            }

            present[convMins] = true;
        }

        int prev, first, last, ans;
        prev = first = last = ans = INT_MAX;
        
        for (int i = 0; i < 24 * 60; ++i) {
            if (present[i]) {
                if (prev != INT_MAX) {
                    ans = min(ans, i - prev);
                }

                prev = i;
                if (first == INT_MAX) {
                    first = i;
                }
                last = i;
            }
        }

        return min(ans, 24 * 60 - last + first);
    }
};