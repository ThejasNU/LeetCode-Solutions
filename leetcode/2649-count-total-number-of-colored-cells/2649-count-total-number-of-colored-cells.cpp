class Solution {
public:
    long long coloredCells(int n) {
        long long x = n;
        return sum(x) + sum(x - 1);
    }

    // first n odd numbers sum
    long long sum(long long n) { return n * n; }
};