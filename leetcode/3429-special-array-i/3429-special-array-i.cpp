class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            bool isEven1 = nums[i - 1] % 2 == 0;
            bool isEven2 = nums[i] % 2 == 0;

            if (isEven1 && isEven2) {
                return false;
            }

            if (!isEven1 && !isEven2) {
                return false;
            }
        }
        return true;
    }
};