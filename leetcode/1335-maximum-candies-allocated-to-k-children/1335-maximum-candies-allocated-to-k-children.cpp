class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 0;
        int right = *max_element(candies.begin(), candies.end());

        while (left < right) {
            int middle = (left + right + 1) / 2;
            if (isPossible(middle, candies, k)) {
                left = middle;
            } else {
                right = middle - 1;
            }
        }

        return left;
    }

private:
    bool isPossible(int num, vector<int>& candies, long long k) {
        long long count = 0;
        for (int candyCnt : candies) {
            count += candyCnt / num;
        }
        return count >= k;
    }
};