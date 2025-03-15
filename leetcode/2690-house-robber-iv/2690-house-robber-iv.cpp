class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 1, right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = (left + right) / 2;
            if (isPossible(mid, nums, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool isPossible(int reward, vector<int>& nums, int k) {
        int possibleThefts = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= reward) {
                possibleThefts += 1;
                ++i;
            }
        }
        return possibleThefts >= k;
    }
};