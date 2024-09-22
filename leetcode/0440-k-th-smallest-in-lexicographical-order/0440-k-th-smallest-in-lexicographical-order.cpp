class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;

        while (k > 0) {
            int step = countSteps(n, cur, cur + 1);
            if (step <= k) {
                ++cur;
                k -= step;
            } else {
                cur *= 10;
                --k;
            }
        }

        return cur;
    }

private:
    int countSteps(int n, long start, long end) {
        int steps = 0;

        while (start <= n) {
            steps += min((long)(n + 1), end) - start;
            start *= 10;
            end *= 10;
        }

        return steps;
    }
};