class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        int x = nums[0], count = 0;
        for (int num : nums) {
            if (num == x) {
                ++count;
            } else {
                --count;
            }

            if (count == 0) {
                x = num;
                count = 1;
            }
        }

        int xCount = std::count(nums.begin(), nums.end(), x);

        count = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == x) {
                ++count;
            }

            int remaining = xCount - count;
            if ((count * 2 > i + 1) && (remaining * 2 > n - i - 1)) {
                return i;
            }
        }

        return -1;
    }
};