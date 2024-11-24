class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int minNum = INT_MAX, count = 0;
        for (auto& row : matrix) {
            for (int num : row) {
                if (num < 0) {
                    ++count;
                }
                ans += abs(num);
                minNum = min(minNum, abs(num));
            }
        }
        if (count % 2 != 0) {
            ans -= 2 * minNum;
        }
        return ans;
    }
};