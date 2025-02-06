class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                m[nums[i] * nums[j]]++;
            }
        }

        int ans = 0;
        for (auto& [prod, cnt] : m) {
            int tuple = cnt * (cnt - 1) / 2;
            ans += 8 * tuple;
        }

        return ans;
    }
};