class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = (left + right) / 2;

            if (isPossible(mid, nums, maxOperations)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool isPossible(int maxBallsInBag, vector<int>& nums, int maxOperations) {
        int totalOps = 0;

        for (int num : nums) {
            int curOps = ceil((double)num / maxBallsInBag) - 1;
            totalOps += curOps;

            if (totalOps > maxOperations) {
                return false;
            }
        }

        return true;
    }
};