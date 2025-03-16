class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long minRank = *min_element(ranks.begin(), ranks.end());
        long long left = 0, right = 1LL * (minRank)*cars * cars;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            for (long long rank : ranks) {
                count += sqrt(mid / rank);
            }
            if (count >= cars) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};