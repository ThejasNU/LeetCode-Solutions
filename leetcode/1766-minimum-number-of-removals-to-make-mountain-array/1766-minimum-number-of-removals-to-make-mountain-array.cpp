class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> lisLen(n, 1);
        vector<int> ldsLen(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    lisLen[i] = max(lisLen[i], 1 + lisLen[j]);
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[i]) {
                    ldsLen[i] = max(ldsLen[i], 1 + ldsLen[j]);
                }
            }
        }

        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (lisLen[i] > 1 && ldsLen[i] > 1) {
                ans = min(ans, n - lisLen[i] - ldsLen[i] + 1);
            }
        }

        return ans;
    }
};