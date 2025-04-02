class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, maxNum = 0, maxDiff = 0;
        for (int k = 0; k < nums.size(); ++k) {
            ans = max(ans, maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxNum - nums[k]);
            maxNum = max(maxNum, (long long)nums[k]);
        }
        return ans;
    }
};