class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        bool isOdd1 = (n1 & 1), isOdd2 = (n2 & 1);
        int ans = 0;

        if (isOdd1) {
            for (int num : nums2) {
                ans ^= num;
            }
        }

        if (isOdd2) {
            for (int num : nums1) {
                ans ^= num;
            }
        }

        return ans;
    }
};