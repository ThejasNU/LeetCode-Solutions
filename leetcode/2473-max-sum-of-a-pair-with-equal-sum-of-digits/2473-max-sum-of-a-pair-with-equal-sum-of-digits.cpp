class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = -1;
        for (int num : nums) {
            int digitSum = 0;
            for (int cur = num; cur > 0; cur /= 10) {
                digitSum += cur % 10;
            }
            if (m.find(digitSum) != m.end()) {
                ans = max(ans, m[digitSum] + num);
                m[digitSum] = max(m[digitSum], num);
            } else {
                m[digitSum] = num;
            }
        }
        return ans;
    }
};