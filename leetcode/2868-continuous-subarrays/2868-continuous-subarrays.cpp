class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();

        map<int, int> m;
        int l = 0, r = 0;
        long long ans = 0;

        while (r < n) {
            m[nums[r]] += 1;

            while (m.rbegin()->first - m.begin()->first > 2) {
                m[nums[l]] -= 1;
                if (m[nums[l]] == 0) {
                    m.erase(nums[l]);
                }
                ++l;
            }

            ans += r - l + 1;
            ++r;
        }

        return ans;
    }
};