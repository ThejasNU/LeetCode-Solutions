class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxNum = 0, maxDiff = 0, ans = 0;
        for (long long num : nums) {
            ans = max(ans, maxDiff * num);
            maxDiff = max(maxDiff, maxNum - num);
            maxNum = max(maxNum, num);
        }
        return ans;
    }
};