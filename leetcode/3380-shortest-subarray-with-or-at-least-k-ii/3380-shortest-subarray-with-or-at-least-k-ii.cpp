class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int start = 0, end = 0;
        vector<int> count(32, 0);

        while (end < nums.size()) {
            updateCount(nums[end], count, 1);

            while (start <= end && getNumber(count) >= k) {
                ans = min(ans, end - start + 1);
                updateCount(nums[start], count, -1);
                ++start;
            }

            ++end;
        }

        return ans == INT_MAX ? -1 : ans;
    }

    void updateCount(int number, vector<int>& count, int delta) {
        for (int i = 0; i < 32; ++i) {
            if ((number >> i) & 1) {
                count[i] += delta;
            }
        }
    }

    int getNumber(vector<int>& count) {
        int num = 0;
        for (int i = 0; i < 32; ++i) {
            if (count[i] > 0) {
                num |= (1 << i);
            }
        }
        return num;
    }
};