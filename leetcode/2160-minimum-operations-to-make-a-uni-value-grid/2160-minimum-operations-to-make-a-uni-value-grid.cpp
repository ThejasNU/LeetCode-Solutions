class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (auto& row : grid) {
            for (int num : row) {
                nums.push_back(num);
            }
        }

        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        int ans = 0;
        for (int num : nums) {
            if (abs(num - median) % x != 0) {
                return -1;
            }
            ans += abs(num - median) / x;
        }

        return ans;
    }
};