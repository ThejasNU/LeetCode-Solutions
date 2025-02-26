class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, curSum = 0;
        for (int num : nums) {
            curSum += num;
            maxSum = max(maxSum, curSum);
            minSum = min(minSum, curSum);
        }
        return maxSum - minSum;
    }
};